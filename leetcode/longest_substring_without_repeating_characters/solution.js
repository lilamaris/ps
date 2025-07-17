/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  let l = 0;
  let max = 0;
  let d = {};

  for (let r = 0; r < s.length; r++) {
    while (d[s[r]]) {
      d[s[l]] = false;
      l++;
    }
    d[s[r]] = true;
    max = Math.max(max, r - l + 1);
  }
  return max;
};
