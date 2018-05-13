string Solution::fractionToDecimal(int numi, int deni) {
    string ans = "";
    string temp = "";
    long long num = numi;
    long long den = deni;
    bool neg= false;
    if((num >= 0 && den >=0) || (num<0 && den<0));
    else neg=true;
    if(num==0 || den==0)neg = false;
    num = abs(num);
    den = abs(den);
    long long oden = den;
    if(num ==0){
        return "0";
    }
    map<long long, long long>mp;
    if(num >= den){
        long q = num / den;
        long rem = num % den;
        mp[rem]=0;
        num = rem;
        ans += to_string(q);
        if(rem == 0)return ans;
        ans += ".";
    }
    else {
        ans += "0.";
        mp[num] = 0;
    }
    int counter = 0;
    while(true){
        counter++;
        num *= 10;
        long long q = num / den;
        long long rem = num % den;
        if(mp.find(rem) != mp.end()){
            if(neg)ans = "-" + ans;
            ans = ans + temp.substr(0,mp[rem]) + "(" + temp.substr(mp[rem])+to_string(q)+ ")";
            return ans;
        }
        else mp[rem]=counter;
        num = rem;
        temp += to_string(q);
        if(rem == 0){
            ans += temp;
            break;
        }
    }
    if(neg)ans = "-" + ans;
    return ans;
}

