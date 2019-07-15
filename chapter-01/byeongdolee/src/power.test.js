const power = require('./power');

test('10^10', () => {
  expect(power(10, 10)).toBe(10000000000);
});

test('2^10', () => {
  expect(power(2, 10)).toBe(1024);
});
