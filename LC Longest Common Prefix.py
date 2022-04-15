class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        min_str = min(strs,key=len)
        while min_str in strs:
            strs.remove(min_str)
        prefix_arr = [min_str[0:i] for i in range(1,len(min_str)+1)]
        prefix_arr.sort(key=len,reverse=True)
        while prefix_arr:
            ans = True
            lng_prfx = prefix_arr[0]
            for i in strs:
                ans = ans & i.startswith(lng_prfx)
            if ans:
                return lng_prfx
            else:
                prefix_arr.remove(lng_prfx)
        else:
            return ""