/**
 * 에라토스테네스의 체(소수판정)
 */
let isPrimeNumber = false;
const start = 1;
const end = 100;

for (i=start; i<=end; i++) {
    isPrimeNumber = true;
    for (j=2; j<=Math.sqrt(i); j++) {   // i의 제곱근까지 루프
        if(i%j == 0) {
            isPrimeNumber = false;
            break;
        }
    }
    if (isPrimeNumber && i != 1) {
        console.log("data? " + i);
        console.log('소수');
    }
}