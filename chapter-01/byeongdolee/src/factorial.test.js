const factorial = require('./factorial');

test('10!', () => {
  expect(factorial(10)).toBe(3628800);
});
