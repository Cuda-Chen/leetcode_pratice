// two pointers

inline int max(int a, int b) {
    return a > b ? a : b;
}

inline int min(int a, int b) {
    return a < b ? a : b;
}

int maxArea(int* height, int heightSize){
    int result = 0;
    int left = 0;
    int right = heightSize - 1;
    
    while(left < right) {
        result = max(result, min(height[left], height[right]) * (right - left));
        
        if(height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    
    return result;
}
