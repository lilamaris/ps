/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (numbers, target) {
  let d = {};
  for (let i = 0; i < numbers.length; i++) {
    const diff = target - numbers[i];
    if (d[diff] !== undefined) return [d[diff], i + 1];
    d[numbers[i]] = i + 1;
  }
};
