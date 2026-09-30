// generate diverse candidate tree exprs (strings) to test
const cands=new Set();
const C='nd([])'; // leaf key2 val0
function node(ch,v){return `nd([${ch.join(',')}],2,${v})`;}
// depth2: k leaves, val v
for(let k=1;k<=4;k++)for(const v of [0,1,2,3,5,7,k,k+1]){const ch=[];for(let i=0;i<k;i++)ch.push(C);cands.add(node(ch,v));}
// depth2 with leaves having vals
for(let k=1;k<=3;k++)for(const v of [0,3,5,7]){const ch=[];for(let i=0;i<k;i++)ch.push(`nd([],2,${i+1})`);cands.add(node(ch,v));}
// depth3: node containing a node
for(const iv of [0,2,3]) for(const ov of [0,3,5,7]) for(let ik=1;ik<=2;ik++){const ich=[];for(let i=0;i<ik;i++)ich.push(C);cands.add(node([node(ich,iv)],ov));}
// depth3 mixed: [innernode, leaf]
for(const iv of [0,2,3]) for(const ov of [0,5,7]){cands.add(node([`nd([${C}],2,${iv})`,C],ov));cands.add(node([C,`nd([${C}],2,${iv})`],ov));}
// balanced: [node,node]
for(const ov of [0,5,7]){cands.add(node([`nd([${C}],2,2)`,`nd([${C}],2,2)`],ov));}
console.log([...cands].join('\n'));
