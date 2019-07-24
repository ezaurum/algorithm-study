
function main() {
    const input = 19; // 19!
    console.log(factorial(input));
}

function factorial(num) {
    if (num <= 1) {
        return num;
    } else {
        return factorial(num-1) * num;
    }
}

console.log(main());

module.exports = factorial;
