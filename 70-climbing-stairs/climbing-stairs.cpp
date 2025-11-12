class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;  // Base cases: 1 → 1 way, 2 → 2 ways
    
    int first = 1, second = 2;  // Represents ways for (n-2) and (n-1)
    int current;

    for (int i = 3; i <= n; i++) {
        current = first + second; 
        first = second;
        second = current;
    }
    
    return second;  
        
    }
};