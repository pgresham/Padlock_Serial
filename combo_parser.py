import re
r = re.compile('.*-.*-.*')
with open('combos.txt','r') as f:
    with open('parsed.txt','w') as p:
        
         for line in f:
            x = line.split()
            if len(x) == 2 and r.match(x[1]) is not None:
                s = x[0]+' '+x[1]+'\n'
                p.write(s)

p.close()
f.close()
