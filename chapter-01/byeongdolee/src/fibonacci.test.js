const fibonacci = require('./fibonacci');

test('fibonacci(80)', () => {
  expect(fibonacci(80)).toBe(23416728348467685);
});
