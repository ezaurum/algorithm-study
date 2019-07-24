String.prototype.format = function(size){
    let thiStr = "";
    if(this.length > size){
        thiStr = this.substr(0,size);
        return thiStr;
    }else {
        thiStr = this.trim();
        for(let j=0;j<size-this.length;j++){
            thiStr = thiStr + " ";
        }
    }
    return thiStr;
}

Number.prototype.format = function(slen,dlen) { // slen: space len, dlen: digit len
    let thisNumber = this.toString();

    //default slen , dlen - 걍 정함
    slen = slen || 8;
    dlen = dlen || 6;

    if(thisNumber.length>slen){
        thisNumber = thisNumber.substr(0,slen);
    }
    if(thisNumber.length>dlen){
        thisNumber = thisNumber.substr(0,dlen);
    }
    if(dlen>slen){
        thisNumber = thisNumber.substr(0,slen-1);
    }

    let resultNumber='';
    for(i=0;i<slen-thisNumber.length;i++)
        resultNumber = resultNumber + ' ';
    resultNumber = resultNumber + thisNumber;

    return resultNumber;
}


function randomNumber (rNumber) {
    rNumber = (109* rNumber +1021) % 32768;
    return rNumber;
}

// 일양난수, 책예제 
function example1(){

    let arrSize = 100;
    let firstRndNumber;
    let rndNum = 13;
    let range;
    let resultStr = '';
    

    for(let i=0;i<arrSize;i++){
        rndNum = randomNumber(rndNum).format(10,6);
        if(i == 0){
            firstRndNumber = rndNum;
        }
        if(i>0 && i%9 ==0){
            resultStr = resultStr + '\n';
        }
        if(firstRndNumber == rndNum && i >0) range = i;
        resultStr = resultStr + rndNum;
    }

    console.log(resultStr);
    //console.log('########### range size: ' + range );
}

// 0~1미만 실수
function mrndNumber (iNumber){
    return iNumber/32767.1;
}

// 일양성 검증, 책 예제
// - 히스토그램, x^2
function example2(){
    
    let occurence = 1000;
    let range = 10;
    let expected = occurence/range;
    let scale = 40;
    let rndNum = 13;
    let rank ;
    let hist = new Array();
    
    //초기화
    for(let i=1;i<=range;i++){
        hist[i] =0;
    }
    
    //난수발생시켜, hist 적재
    for(i=0;i<occurence;i++){
        rndNum = randomNumber(rndNum);
        rank = range * mrndNumber(rndNum) + 1;      // 1~10
        //console.log("rank: " + Math.floor(rank) );
        hist[Math.floor(rank)]++;
    }

    
    let resultStr = '';
    let x2=0;
    //출력 아웃, x^2
    for(i=1;i<=range;i++){
        resultStr = resultStr + ("hist[" + i + "] :" + hist[i]).format(20) + "   I";
        for(let j=0;j<hist[i];j++){
            resultStr = resultStr + "*";
        }
        resultStr = resultStr + "\n";
        
        // x^2
        x2 = x2 +(hist[i] - expected) * (hist[i] - expected) / expected ;
    }
    console.log(resultStr);
    console.log("x^2: " + x2);
    
}

// 전역 구간 
let x = 0;
let y = 0;

// 박스-뮬러, 책 예제
function example3(){
    let occurence = 100;
    let range = 100;
    let hist = new Array();

    //초기화
    for(let i=0;i<range;i++){
        hist[i] = 0;    
    }

    //난수 발생/적재
    for(i=0;i<occurence;i++){
        brnd(2.5,10);
        //console.log('x: '+ x + ', y: ' + y);

        hist[Math.floor(x)]++;
        hist[Math.floor(y)]++;
    }

    //출력 관련 
    let size = 20;
    let resultStr = '';
    for(i=0;i<=size;i++){
      resultStr = resultStr + ('hist[' + i + ']: ' + hist[i] ).format(18) + '   I';
      //console.log('hist[' + i + ']' + hist[i]);
      for(let j=0;j<hist[i];j++){
          resultStr = resultStr + '*';
      }
      resultStr = resultStr + '\n';
    }

    console.log(resultStr);

}

function rand(range, from){
    let max = range -1;
    if(typeof from ==='undefined'){
        return Math.random() * range;
    }
    return Math.random() * range + from ;
}

function brnd(sigma, m){
    let randMax = 99;
    
    let pi = 3.14150;
    
    let r1 = rand(randMax+1) / randMax; // randMax는 내맘대로? - todo 
    let r2 = rand(randMax+1) / randMax;
    x = sigma * Math.sqrt(-2*Math.log(r1))*Math.cos(2*pi*r2) + m;
    y = sigma * Math.sqrt(-2*Math.log(r1))*Math.sin(2*pi*r2) + m;
    
}

example1();

example2();

example3();