const horner = require('./horner');

test('f(x) = 5x^4 + 4x^3 + 3x^2 + 2x + 1', () => {
  expect(horner(5, [5, 4, 3, 2, 1])).toBe(3711);
});

test('f(x) = 10x^6 + 3x^3 + 100x^2 + 4x + 3', () => {
  expect(horner(10, [10, 0, 0, 3, 100, 4, 3])).toBe(10013043);
});
