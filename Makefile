# Params
SOURCE = $(wildcard app/src/*.cpp)
OBJECTS = $(patsubst app/src/%.cpp, app/build/%.o, $(SOURCE))
GNUPARAMS = -Iapp/include

# Fundamental Recipes
app/build/%.o: app/src/%.cpp
	mkdir -p app/build
	g++ $(GNUPARAMS) -o $@ -c $<


app/bin/main.exe: $(OBJECTS)
	mkdir -p app/bin
	g++ $(GNUPARAMS) -o $@ $(OBJECTS)


# Final Recipes
.PHONY: run clear
run: app/bin/main.exe
	$<

clear:
	rm -rf app/build app/bin