#include<GL/glut.h>
#include<math.h>
#include<random>
#include<iostream>
#include<vector>
#include<Windows.h>
#define sleep(x) Sleep(1000 * (x))
int N = 50;
std::vector<int> nums(N, 0);
std::string algoName;
void visual(std::vector<int> nums);
void visualSearch(std::vector<int> nums, int x,int y);
void myinit();

#include"head.h"


void rect(int x1, int y1, int x2, int y2) {
	glBegin(GL_POLYGON);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);
	glEnd();
}

void visual(std::vector<int> nums) {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	glRasterPos2f(250,400);
	for (auto i : algoName) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, i);
	}

	for (int i = 0; i < N; i++) {
		rect( 4*(i+10), 0, 4*(i+10) + 3, nums[i]);
	}
	//sleep(0.5);
	glFlush();
}

void visualSearch(std::vector<int> nums, int x, int y) {
	glClear(GL_COLOR_BUFFER_BIT);
	visual(nums);
	sleep(1);
	glColor3f(1, 0, 0);
	rect(4 * (x + 10), 0, 4 * (x + 10) + 3, y);
	glFlush();
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0);
	visual(nums);
	sleep(2);
	//Selection Sort
	algoName = "Selection Sort";
	std::vector<int> vec(N,0);
	for (int i = 0; i < N; i++) {
		vec[i] = nums[i];
	}
	selectionSort sel(vec, N);
	sleep(2);
	//Merge Sort
	algoName = "Merge Sort";
	for (int i = 0; i < N; i++) {
		vec[i] = nums[i];
	}
	mergeSort merge(vec, N);
	sleep(2);
	//Insertion Sort
	algoName = "Insertion Sort";
	for (int i = 0; i < N; i++) {
		vec[i] = nums[i];
	}
	insertionSort insert(vec, N); 
	sleep(2);
	//Quick Sort
	algoName = "Quick Sort";
	for (int i = 0; i < N; i++) {
		vec[i] = nums[i];
	}
	quickSort quick(vec, N);
	sleep(2);
	//Shell Sort
	algoName = "Shell Sort";
	for (int i = 0; i < N; i++) {
		vec[i] = nums[i];
	}
	shellSort shell(vec, N);
	sleep(2);
	//Binary Search
	algoName = "Binary Search";
	for (int i = 0; i < N; i++) {
		vec[i] = nums[i];
	}
	selectionSort selsort(vec, N);
	binarySearch find(vec, N,vec[30]);
	glFlush();
}

void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(5.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}

void main(int argc, char** argv) {
	for (int i = 0; i < N; i++) {
		nums[i] = (rand() % 100);
	}
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("ALGO!");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}
