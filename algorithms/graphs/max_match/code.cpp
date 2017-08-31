#include <bits/stdc++.h>

#define UNMATCHED -1
#define MAX 500
#define vi vector<int>
#define A 1
#define B 0

using namespace std;

int size1, size2, n;
vi graph[MAX];
int matched[MAX];
bool visited[MAX];

struct vertex {
  int type;
  int id;
    vertex(int type = A, int id = 0){
        this->type = type;
        this->id = id;
    }
};

int vertex_to_id(vertex v) {
  return ((v.type == A) ? 0 : size1) + v.id;
}

vertex id_to_vertex(int id) {
  vertex ret;
  if(id < size1) ret = vertex(A,id);
  else ret = vertex(B,id - size1);
  return ret;
}

bool augment_path(int id) {

  visited[id] = true;

  for(int i = 0; i < graph[id].size(); i++) {
    int neigh = graph[id][i];
    if(visited[neigh]) continue;

    if(matched[neigh] == UNMATCHED) {
        matched[id] = neigh; matched[neigh] = id;
        return true;
    }
    else if(matched[neigh] != id) {
        visited[neigh] = true;
        if (augment_path(matched[neigh])) {
            matched[id] = neigh; matched[neigh] = id;
            return true;
        }
    }
  }

  return false;
}

int main() {

  fill(matched, matched + MAX, UNMATCHED);
  scanf("%d %d %d\n", &size1, &size2, &n);
  vertex vertex1, vertex2;
  int id1, id2;

  for (int i = 0; i < num_edges; i++) {
    scanf("%d %d %d %d\n", &vertex1.type, &vertex1.id, &vertex2.type, &vertex2.id);
    id1 = vertex_to_uid(vertex_A);
    id2 = vertex_to_uid(vertex_B);

    graph[id1].push_back(id2);
    graph[id2].push_back(id1);
  }

  int answer = 0;
  for(int i = 0; i < size1; i++) {
    if(matched[i] == UNMATCHED) {
      fill(visited, visited + MAX, false);
      if(augment_path(i)) answer++;
    }
  }

  printf("Size of maximum matching: %d\n", answer);
  for (int i = 0; i < size_A; i++) {
    if (matched[i] != UNMATCHED) {
      vertex matched1 = uid_to_vertex(i);
      vertex matched2 = uid_to_vertex(matched[i]);
      printf("A%d B%d\n", matched1.id, matched2.id);
    }
  }

  return 0;
}
