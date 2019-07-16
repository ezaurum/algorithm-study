const combination = require('./combination');

test('5C3', () => {
  expect(combination(5, 3)).toBe(10);
});

test('10C5', () => {
  expect(combination(10, 5)).toBe(252);
});
