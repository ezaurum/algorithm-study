/**
 * 직접 선택법에 의한 정렬
 */

const N = 6;
function main() {
    const numbers = [80, 41, 35, 90, 40, 20];
    let min = 0;
    let s = 0;
    let t = 0;
    let i = 0;
    let j = 0;

    for (i=0; i<N-1; i++) {
        min = numbers[i];
        s=i;
        for(j=i+1; j<N; j++) {
            if(numbers[j] < min) {
                min = numbers[j];
                s=j;
            }
        }
        t = numbers[i];
        numbers[i] = numbers[s];
        numbers[s] = t;
    }

    for(i=0; i<N; i++) {
        console.log(numbers[i]);
    }
    return '';
}
function main2() {
    const data = [80, 41, 35, 90, 40, 20];
    let temp = 0;
    
    for (let i=0; i<data.length - 1; i++) {
        for(let j=i+1; j<data.length; j++) {
            if (data[i] > data[j]) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
        console.log(i + ': ' + data);  // 현재 i번째 데이터 출력
    }
    
    console.log();
    console.log('----- 정렬결과 -----');
    for(let i=0; i<data.length; i++) {
        console.log(data[i]);
    }
    return '';
}

 console.log(main2());