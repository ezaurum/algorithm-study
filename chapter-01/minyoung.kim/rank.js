const Num = 10;

function main () {    
    const a = [56, 25, 57, 88, 100, 61, 55, 67, 76, 56];
    const rank = new Array(Num);
    let i;
    let j;

    for (i=0; i<Num; i++) {
        rank[i] = 1;
        for(j=0; j<Num; j++) {
            if(a[j] > a[i]) {
                rank[i]++;
            }
        }
    }    
    console.log('점수   순위');
    for(i=0; i<Num; i++) {
        console.log(a[i] + '    ' + rank[i]);
    }
    return '';
}

console.log(main());
