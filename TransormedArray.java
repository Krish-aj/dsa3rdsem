class Solution {
    public int[] constructTransformedArray(int[] nums) {
        int[] result= new int[nums.length];
        int length=nums.length;
        
        for(int i=0;i<nums.length;i++){
            
            if(nums[i]==0){
                result[i]=nums[i];
            }
            else{
                  int newindex = ((i+nums[i])%length+length)%length; //this handles both negative and postive circularly
                    //((current index +steps)% array length+ length)% length;   {this is the structure to handle array circularly}
                   result[i]=nums[newindex];
                   
            }
        }
        return result;
    }
}
