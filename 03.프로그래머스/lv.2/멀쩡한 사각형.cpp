using namespace std;

long long solution(int w,int h)
{
    int gcd = 0;
    
    for(int i= w > h ? w : h; i>=1; i--) {
        if(w%i == 0 && h%i == 0) {
            gcd = i;
            break;
        }
    }
    long long sum = (long long)w * (long long)h;
    return sum - gcd * ((w/gcd) + (h/gcd) -1);
}
