vector<int> Solution::grayCode(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int>sol;
    vector<int>xxx;
    //for(int i = 0; i < n-2; i++)A.push_back(0);
    //A.push_back(1);
    //A.push_back(0);
    if(A == 0)return sol;
    sol.push_back(0);
    sol.push_back(1);
    if(A == 1)return sol;
    xxx.push_back(0);xxx.push_back(1);
    int plus = 2;
    A-= 1;
    while(A--){
        for(int i = plus-1; i >=0 ; i--){
            sol.push_back(xxx[i] + plus);
            xxx.push_back(xxx[i] + plus);
        }
        plus *= 2;
    }
    
    return sol;
}
