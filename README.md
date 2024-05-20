# Projet de Recherche Locale pour le Problème du Voyageur de Commerce

## Description

Ce projet implémente diverses méthodes de recherche locale pour résoudre le problème du voyageur de commerce (TSP). Il comprend des algorithmes de base comme l'échange, la réinsertion, et le 2-opt, ainsi que des variantes plus avancées comme la recherche locale à voisinage variable et la recherche locale itérée.

## Structure du Projet

- **include/** : Contient les fichiers d'en-tête (.h) pour les différentes classes.
    - **City.h** : Définition de la classe City.
    - **Instance.h** : Définition de la classe Instance.
    - **Solution.h** : Définition de la classe Solution.
    - **Solver.h** : Définition de la classe Solver et ses dérivés.
    - **neighbor/** : Contient les classes de voisinage (Neighbor).
        - **Neighbor.h** : Interface pour les classes de voisinage.
        - **EchangeNeighbor.h** : Voisinage par échange.
        - **ReinsertionNeighbor.h** : Voisinage par réinsertion.
        - **TwoOptNeighbor.h** : Voisinage par 2-opt.
    - **search/** : Contient les classes de recherche.
        - **Search.h** : Interface pour les classes de recherche.
        - **local/** : Contient les implémentations de recherche locale.
            - **LocalSearch.h** : Implémentation de la recherche locale de base.
            - **IteratedLocalSearch.h** : Implémentation de la recherche locale itérée.
            - **VariableNeighborhoodSearch.h** : Implémentation de la recherche locale à voisinage variable.

- **src/** : Contient les implémentations des classes.
    - **City.cpp**
    - **Instance.cpp**
    - **Solution.cpp**
    - **neighbor/** : Implémentations des classes de voisinage.
        - **EchangeNeighbor.cpp**
        - **ReinsertionNeighbor.cpp**
        - **TwoOptNeighbor.cpp**
    - **search/** : Implémentations des classes de recherche.
        - **local/** : Implémentations des recherches locales.
            - **LocalSearch.cpp**
            - **IteratedLocalSearch.cpp**
            - **VariableNeighborhoodSearch.cpp**

- **assets/** : Contient les fichiers d'instance pour les tests.

- **main.cpp** : Point d'entrée du programme pour exécuter et tester les algorithmes.

## Fonctionnalités

### Classes de Base

- **City** : Représente une ville avec un nom, une latitude et une longitude. Inclut des méthodes pour calculer la distance entre deux villes.
- **Instance** : Charge et stocke une liste de villes à partir d'un fichier.
- **Solution** : Représente une solution pour le TSP, avec des méthodes pour évaluer la solution, mélanger les villes, insérer ou supprimer des villes, etc.

### Solvers

- **RandomSolver** : Mélange aléatoirement les villes pour générer une solution.
- **GreedySolver** : Utilise une approche gloutonne pour générer une solution initiale.

### Recherche Locale

- **LocalSearch** : Implémente la recherche locale de base.
- **IteratedLocalSearch** : Étend `LocalSearch` pour inclure des perturbations et des itérations pour améliorer la solution.
- **VariableNeighborhoodSearch** : Implémente la recherche locale à voisinage variable.

### Voisinages

- **EchangeNeighbor** : Génère des solutions voisines en échangeant deux villes.
- **ReinsertionNeighbor** : Génère des solutions voisines en réinsérant une ville à une autre position.
- **TwoOptNeighbor** : Génère des solutions voisines en inversant l'ordre des villes entre deux indices.

## Instructions d'Utilisation

1. **Compiler le Projet**

   Utilisez un compilateur C++ pour compiler le projet. Par exemple, avec g++ :

   ```bash
   g++ -o tsp main.cpp src/**/*.cpp -Iinclude

2. **Exécuter le Programme**

   Exécutez le programme avec la commande suivante :

   ```bash
   ./tsp
   ```
