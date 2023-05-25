import queue as Q

dict_hn = {'A':336,'B':374,'C':380,'D':253,'E':193,'F':176,'G':100,'H':0}

dict_gn = dict(
	A=dict(B=75,D=140),
	B=dict(A=75,C=71),
	C=dict(B=71,D=151),
	D=dict(A=140,C=151,F=99,E=80),
	E=dict(G=97,D=80),
	F=dict(H=211,D=99),
	G=dict(E=97,H=101),
	H=dict(F=211,G=101)
)

start = "A"
goal = "H"

result = ""

def get_fn(city):
	cities = city.split(",")
	hn=gn=0
	
	for i in range(0,len(cities)-1):
		gn = gn + dict_gn[cities[i]][cities[i+1]]
		hn = dict_hn[cities[len(cities)-1]]
	
	return (hn+gn)
	
def expand(cityq):
	global result
	total, city, thiscity = cityq.get()
	
	if thiscity == goal :
		result = city+"::"+str(total)
		return
	else:
		for j in dict_gn[thiscity]:
			cityq.put((get_fn(city+","+j), city+","+j, j))
			
	expand(cityq)
	
def main():
	cityq = Q.PriorityQueue()
	thiscity = start
	cityq.put((get_fn(start),start,thiscity))
	expand(cityq)
	print("A* path : ")
	print(result)
	
main()	