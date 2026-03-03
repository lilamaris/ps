/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
  let arr = [...nums1, ...nums2].sort((a, b) => a - b);
  if (arr.length % 2 === 0) {
    let [ml, mr] = [arr.length / 2 - 1, arr.length / 2];
    return (arr[ml] + arr[mr]) / 2;
  } else {
    return arr[Math.floor(arr.length / 2)];
  }
};
