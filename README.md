# Philosophers 
Le projet Philosophers met en oeuvre les concepts suivant : thread, mutex, data race.

## Description du projet
Un groupe de philosophes sont assis autour d'une table, alternant entre manger, dormir et penser. Autour de la table il y a autant de fourchettes qu'il y a de 
philosophe, pour manger un philosophe a besoin de deux fourchette. Le programme s'arrête à partir du moment où un philosophe meurt de faim.

## Concepts étudié

### Threads
Un thread est une suite logique d'instructions à l'intérieur d'un processus qui est gérée par le noyeau du système d'exploitation. Chaque thread d'un processus possède son contexte : son propre id, sa pile d'exécution/stack, son ptr d'instruction, son registre de processeur. 
Tout les threads font partie du même processus, ils partagent le même espace (le même code, la même heap, les mêmes bibliothèques, les mêmes fds).

Pour un système il est bien plus rapide de créer un thread que de créer un processus car son contexte est plus petit que celui d'un processus en termes de ressources. Les threads n'ont pas non plus une stricte hiérarchie père-fils des processus, ils forment un ensemble de pairs qui ne dépend pas de quel thread a crée quel autre thread. Donc n'importe quel thread peut tuer ou attendre la fin de n'importe quel autre thread du même processus.

Chaque thread peut aussi lire et écrire sur la même mémoire virtuelle.

- **Pourquoi ?** Les threads permettent de simuler le comportement simultané des philosophes, donc chaque philosophe est lancé dans un thread distinct.

### Data Race
Le data race survient quand plusieurs tâches ou bien plusieurs threads accède à une ressource partagée sans suffisamment de protection, cela mène à un comportement inattendu.
Dans un cas plus concret, une situation de compétition (data race) se passe quand deux ou plusieurs threads essaye d'accéder et de modifier la même variable en même temps, cela peut mener à une erreur dans la valeur finale de la variable.

- **Pourquoi l'éviter ?** Les data races rendent le comportement du programme imprévisible pouvant entraîner des crashs ou des incohérences.

### Mutex
C'est un verrou qui permet de réguler l'accès aux données et empêcher que les ressources partagées soient utilisées en même temps.

- **Pourquoi ?** Sans mutex, deux philosophes pourraient saisir la même fourchette en même temps et cela provoquerait des erreurs dans la simulation.
