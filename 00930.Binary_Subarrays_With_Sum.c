int numSubarraysWithSum(int* A, int ASize, int S){
    int c[30005], cc, i, j, ans;
    // c[x] is the number of 0s after x'th 1 in A array
    // for example, A = [1,0,1,0,0,1], c = [0,1,2,0]
    cc = ans = 0;
    for (i = j = 0; i <= ASize; ++i) { // use i == ASize for boundary handling
        if (i == ASize || A[i] == 1) {
            c[cc++] = j;
            j = 0;
            if (cc > S) {
                if (S == 0) // only compute the intervals of 1 and 1.
                    ans += ((c[cc-1]+1) * (c[cc-1])) / 2;
                else
                    ans += (c[cc-1]+1) * (c[cc-1-S]+1);
            }
        }
        else
            j++;
    }
    return ans;
}

