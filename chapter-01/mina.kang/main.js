



function combi (n,r) {
    // nC0 = 1 
    
    let ncr = 1;
    
    for(let i=1;i<=r;i++){
      ncr = ncr * ((n-i) + 1)/i;
    }
    
    return ncr;

}

for(let i=0;i<10;i++){
    let result = '';
    for(let j=0;j<=i;j++){
      result += "     " + i+'C'+j+"=" + combi(i,j) ;
    }
    console.log(result);
   result = '';
}
