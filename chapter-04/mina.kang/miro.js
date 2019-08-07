const miro = [[2,2,2,2,2,2,2],
                  [2,0,0,0,0,0,2],
                  [2,0,2,0,2,0,2],
                  [2,0,0,2,0,2,2],
                  [2,2,0,2,0,2,2],
                  [2,0,0,0,0,0,2],
                  [2,2,2,2,2,2,2]];
let success = 0;

const si =  1; const sj = 1;
const ei =5 ; const ej = 5;

let displayTraceStr = "";

const visito = (i, j) => {    
    miro[i][j] = 1;

    
    
    if(ei === i && ej === j){
        success = 1;
        return success;
    }

    if(success != 1 && miro[i][j+1]=== 0 ) visito(i,j+1);
    if(success != 1 && miro[i+1][j]=== 0 ) visito(i+1,j);
    if(success != 1 && miro[i-1][j]=== 0 ) visito(i-1,j);
    if(success != 1 && miro[i][j-1]=== 0 ) visito(i,j-1);

    if(success ===1 )
    displayTraceStr = displayTraceStr + `(${i},${j})` + '  '; 

    return success;
};



if(visito(si,sj)===0){
    console.log("출구못찾음 ");
}else{
    console.log(displayTraceStr);
}