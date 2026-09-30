const out=[];
const C='nd([])'; // leaf
function node(ch,k,v){return `nd([${ch.join(',')}],${k},${v})`;}
function leaves(n){return Array.from({length:n},()=>C);}
// vary key K (1..5), children count n (0..5), val relations
for(let K=1;K<=5;K++)for(let n=0;n<=5;n++){
  const ch=leaves(n);
  const rels=new Set([0,1,2,K,n,K*n,Math.pow(K,n),Math.pow(2,n),2*n,n+1,K+1,K-1,2*n+1, n===0?2:2*n, K**n+1, K**n-1]);
  for(const v of rels){ if(v>=0 && v<10000 && Number.isInteger(v)) out.push(node(ch,K,v)); }
}
// depth-3: node whose child is node(2,2,[C])  (a certified '3'? try)
for(let K=1;K<=4;K++)for(const v of [2,3,4,5,6,7,8,9]){
  out.push(node([`nd([${C}],2,3)`],K,v));
  out.push(node([`nd([${C},${C}],2,5)`],K,v));
}
console.log([...new Set(out)].join('\n'));
