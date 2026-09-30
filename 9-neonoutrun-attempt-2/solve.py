# Recompute the neon string from the game script carved out of the V8 heap (game.js)
import re, json
js = open('game.js').read()
messages = json.loads(re.search(r'const messages=(\[.*?\]);', js).group(1))
lapmap = json.loads(re.search(r'map=(\[.*?\]);', js).group(1))
neon = ''.join(messages[i // 2][lapmap[i]] for i in range(28))
neon += ''.join(map(chr, [64,102,49,97,114,101,45,111,110,46,99,111,109]))
print(neon.replace(' ', '_'))
