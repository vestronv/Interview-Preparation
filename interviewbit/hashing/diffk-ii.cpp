int Solution::diffPossible(const vector<int> &A, int B) {
    int sz = A.size();
    if(sz <= 1)return 0;
    map<long long,vector<int> >mp;
    mp[A[0]].push_back(0);
    for(int i = 1; i < sz; i++){
        int to_find1 = (A[i] + B);
        int to_find2 = (A[i] - B);
        if(mp.find(to_find1) != mp.end()){
            vector<int>v = mp[to_find1];
            for(int j = 0; j < v.size(); j++){
                if(v[j] != i)return 1;
            }
        }
        else if(mp.find(to_find2) != mp.end()){
            vector<int>v = mp[to_find2];
            for(int j = 0; j < v.size(); j++){
                if(v[j] != i)return 1;
            }
        }
        mp[A[i]].push_back(i);
    }
    return 0;
}
