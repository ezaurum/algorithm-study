const factorial = require('../factorial');

describe('TEST', () => {
    test('factorial', () => {
        expect(factorial(19)).toBe(121645100408832000);
    })
})
  