pos.png vel.png phase.png: try.txt MG_graph.py
	python MG_graph.py
try.txt: ./gravedad
	./gravedad  > try.txt
gravedad: MG_gravity.cpp
	c++ MG_gravity.cpp -o gravedad
