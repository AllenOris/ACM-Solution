# L.Marisa’s Cake

> 题目链接：[https://nanti.jisuanke.com/t/29339](https://nanti.jisuanke.com/t/29339)
>
> 题解作者：[LeFlacon](https://github.com/LeFlacon)
>

## 题意

给一个凸n边形，n个点任选大于等于三个点，求所有情况的面积之和，答案为2S%(1e9+7)，n<1e6

----------
## 题解

面积用叉积算（计算几何里计算多边形面积）
$$\sum_{i=1}^{n}(C_{i}*C_{i+1}) \quad if(i==n)C_{i+1}=C_{1}$$

随便展开n=5时的情况可以发现，每一项$C_{i}*C_{j}$其实有重复计算，因此试图求出$C_{i}*C_{j}$前的系数，任取两个点i，j，假设有$(j<i)$然后考虑在j到i的逆时针方向区域内取点和在二者外部取点，易得方法数是个组合数的和，即$2^{?}-1$

最终会得到如下公式

$$\sum_{i=1}^{n}\sum_{j=1}^{i-1}[(2^{i-j-1}-1)(C_{i}*C_{j})+(2^{n-i+j-1}-1)(C_{j}*C_{i})]$$

化简推出的公式如下 但是照这个公式过不了样例
$$\sum_{i=1}^n 2^{i-1}C_{i}*(\sum_{j=1}^{i-1}2^{-j}C_{j})- \sum_{i=1}^n 2^{n-i-1}C_{i}*(\sum_{j=1}^{i-1}2^{j}C_{j})$$

因为我愚蠢的忘了前后是在一个循环算的，二者循环次数不同，所以应将公式改为
$$\sum_{i=1}^n 2^{i-1}C_{i}*(\sum_{j=1}^{i-1}2^{-j}C_{j})- \sum_{i=1}^n 2^{n-i}C_{i}*(\sum_{j=1}^{i-1}2^{j-1}C_{j})$$

              ①              ②              ③              ④


本来算上面这个式子要i和j都算过去，这样的复杂度是O(n^2),所以考虑优化，这里利用前缀和的思想，把上面这个式子分成四部分来看，第二和四部分利用前缀和每次累加上新的一个$ (2^{-j}C_{j})$，具体见代码，所以最后这个问题只要O(n)扫一遍就好啦

开头要预处理 $2^{i}$ 和 $2^{-i}$ 

然后由于我又愚蠢的初始化反了nx，ny，mx，my的值。。。就一直deeeeeeeebug

被注释掉的那段代码是求2的逆元用的，后来发现其实没啥用。。直接$inv2=(1e9+7+1)/2$ 多省事。。

----------

    #include <algorithm>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <iostream>
    #include <fstream>
    #include <map>
    #include <queue>
    #include <string>
    #include <set>
    #include <cmath>
    using namespace std;
    
    #define LL long long
    const int N=100005;
    const LL inv2=500000004;
    const LL p=1000000007;
    LL pow2[N],inv[N];
    struct node{
    	LL x,y;
    }tmp[N];
    void init(){
    	pow2[0]=inv[0]=1;
    	for(int i=1;i<N;i++){
    		pow2[i]=(pow2[i-1]*2)%p;
    		inv[i]=(inv[i-1]*inv2)%p;
    	}
    }
    LL mul(LL x1,LL y1,LL x2,LL y2){
    	return (x1*y2%p-x2*y1%p+p)%p;
    }
    /*
    LL pow_mod(LL a,LL b,LL p){
        LL ret=1;
        while(b){
            if(b&1)ret=(ret*a)%p;
            a=(a*a)%p;
            b>>=1;
        }
        return ret;
    }
    LL Fermat(LL a,LL p){
            return pow_mod(a,p-2,p);
    }
    */
    int main(){
    	int t,n;
    	LL ans;
    	scanf("%d",&t);
    	init();
    	while(t--){
    		// printf("%lld",Fermat(2,1000000007));
    		ans=0;
    		scanf("%d",&n);
    		for(int i=1;i<=n;i++)scanf("%lld%lld",&tmp[i].x,&tmp[i].y);
    		LL nx=inv2*tmp[1].x%p,ny=inv2*tmp[1].y%p;
    		LL mx=tmp[1].x%p,my=tmp[1].y%p;
    		// cout<<nx<<" "<<ny<<" "<<mx<<" "<<my<<endl; 
    		for(int i=2;i<=n;i++){
    			ans=(ans+mul(pow2[i-1]*tmp[i].x%p,pow2[i-1]*tmp[i].y%p,nx,ny)+p)%p;
    			nx=(nx+inv[i]*tmp[i].x%p)%p;
    			ny=(ny+inv[i]*tmp[i].y%p)%p;
    			ans=(ans-mul(pow2[n-i]*tmp[i].x%p,pow2[n-i]*tmp[i].y%p,mx,my)+p)%p;
    			mx=(mx+pow2[i-1]*tmp[i].x%p)%p;
    			my=(my+pow2[i-1]*tmp[i].y%p)%p;
    		}
    		printf("%lld\n",ans%p);
    	}
    	return 0;
    }

----------







