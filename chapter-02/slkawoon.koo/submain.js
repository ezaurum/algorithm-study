const Y = (num) => num * num + 2 * num + 2;

const main = () => {
  let {h, n, b, a, x, s, result} = 0;
  b = 10;
  a = 5;
  n = 50;
  h = (b - a) / n;
  x = a;
  s= 0;
  for( var i = 1; i <= n - 1; i++) {
      x = x + h;
      s = s + Y(x);
  }
  result = (h * (Y(a) + Y(b)) / 2 + s);
  return result;
};

console.log(main());