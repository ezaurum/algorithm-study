//(a+(b*c)) => abc*+
//((a+t)*((b+(a+c))^(c+d))) => at+bac++cd+^*

function transform(expr) {
    var op = []; // stack
    var newExpr = '';

    for(var ch of expr) {
        console.log(ch);
        if (ch == '(') {
            continue;
        } else if (ch >= 'a' && ch <= 'z') {
            newExpr += ch
        } else if (ch == ')') {
            newExpr += op.pop();
        } else {
            op.push(ch)
        }
    }
    return newExpr;
}

console.log(transform('(a+(b*c))'));