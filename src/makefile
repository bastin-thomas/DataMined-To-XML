#Fichier de création

#Silent pour echo:
.SILENT:

#Librairie a compiler pour l'app final
LibFilm = ./Film
LibGenre = ./Film/Genre
LibDirector = ./Film/Director
LibUtility = ./UtilityLib
LibActor = ./Film/Actor

AppName = DataminedToXML

#Repertoire de tout les .o (Parfois en fichier Cacher)
*.o = $(bin)/UtilityLib.o $(bin)/Film.o $(bin)/Director.o $(bin)/Genre.o $(bin)/Actor.o
bin = ./obj

#Application Final:
$(AppName):	main.cpp $(*.o)
		echo Creation de $(AppName).app
		g++ main.cpp $(*.o) -o $(AppName).app

$(bin)/Film.o:	$(LibFilm)/film.cpp $(LibFilm)/film.hpp
		echo Creation de Film.o
		g++ $(LibFilm)/film.cpp -c -o $(bin)/Film.o

$(bin)/Genre.o:	$(LibGenre)/genre.cpp $(LibGenre)/genre.hpp
		echo Creation de Genre.o
		g++ $(LibGenre)/genre.cpp -c -o $(bin)/Genre.o

$(bin)/Director.o:	$(LibDirector)/director.cpp $(LibDirector)/director.hpp
		echo Creation de Director.o
		g++ $(LibDirector)/director.cpp -c -o $(bin)/Director.o

$(bin)/Actor.o:	$(LibActor)/actor.cpp $(LibActor)/actor.hpp
		echo Creation de Actor.o
		g++ $(LibActor)/actor.cpp -c -o $(bin)/Actor.o

$(bin)/UtilityLib.o:	$(LibUtility)/utilitylib.cpp $(LibUtility)/utilitylib.hpp
		echo Creation de UtilityLib.o
		g++ $(LibUtility)/utilitylib.cpp -c -o $(bin)/UtilityLib.o

#Clean/Clear des .o et de l'application
clean:	
		rm $(*.o)
		rm $(AppName).app
		clear

clear:	
		rm $(*.o)
		rm $(AppName).app
		clear