function homework(ar, tar) {
    var arr = ar;
    var target = tar;
    var result = [];

    arr.forEach((item) => {
        //console.log(item);
        arr.forEach((item2, index) => {
            if (item + item2 === target) {
                result.push(index)
            }
        });
    });

    return result.reverse();
}

console.log(homework([2, 5, 6, 1, 10], 6));
