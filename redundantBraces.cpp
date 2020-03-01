int Solution::braces(string A) {

    int operators_count = 0;
    int open_brace_count = 0;
    int length = A.size();

    for(int ind=0; ind<length; ind++) {
        
        if(A[ind] == '(')
            open_brace_count += 1;

        else if(A[ind]==')') {

            open_brace_count -= 1;
            operators_count -= 1;

            //if at any instant number of closed braces > open braces, 
            //  given expression has inbalanced paranthesis
            if(open_brace_count < 0)
                return 1;

            //handling the case of "(x)"
            if(ind>=2 && A[ind-2]=='(')
                return 1;
        }

        else if(A[ind] == '+' || A[ind] == '-' || A[ind] == '*' || A[ind] == '/')
            operators_count += 1;
    }

    if(open_brace_count > operators_count)
        return 1;

    return 0;
}

