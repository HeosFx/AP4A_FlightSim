# 1. AP4A - Projet : Rendu intermédiaire

## 1.1. Contexte

Ce programme permet de simuler l'écosystème de capteurs interne d'un avion de ligne. Quatre types de capteurs sont mis en relation avec un serveur par l'intermédiaire d'un scheduler :
  - Capteur de température
  - Capteur d'humidité
  - Capteur de pression
  - Capteur de lumière

## 1.2. Mise en situation

Le scheduler récupère, à un intervalle de temps donné, les informations générées par les capteurs pour les transmettre au serveur. Ce dernier va logger les informations dans des fichiers ou/et les afficher dans la console.

Les capteurs génèrent les informations dimensionnées pour s'approcher au plus de la réalité :
  - Température moyenne de 23°C avec une dispertion de 3°C
  - Humidité idéale de 20% avec une dispertion de 8%
  - Pression moyenne de 79289 Pa avec une dispertion de 3447 Pa
  - Intensité lumineuse moyenne de 10000 L avec une dispertion de 1000 L (On suppose que le vol s'effectue lors d'une journée, au alentours de 12H)

## 1.3. Utilisation du programme

Il est nécessaire pour le bon fonctionnement du programme d'executer FlightSim.exe depuis le répertoire FlightSim.

Une fois lancé, l'utilisateur pourra idiquer le temps de simulation (en secondes) ainsi que la période séparant les mesures (en secondes). Il devra ensuite idiquer s'il veux logger les mesures et/ou les afficher. Il faudra ensuite attendre la fin de l'exécution.

## 1.4. Crédits

Cette implémentation de la simulation d'un écosystème de capteur à été réalisée dans l'UV AP4A, au cours du semestre d'Automne 2022. <br>
Auteur : Flavian THEUREL