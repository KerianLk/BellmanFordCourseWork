#pragma once
#include <string>
#include <iostream>
#include <iterator>
#include <vector>
#include <limits>
#include <fstream>
#include <list>
#include <msclr/marshal_cppstd.h>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <set>
#include <commdlg.h>

namespace Graph {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace std;

	int INF = 10000;
	typedef struct Edge {
		int u, v, w;
	};

	struct AlgoritmResults {
		vector<int> distances, edgePath;
	} typedef AlgoritmResults;
	vector<Edge> edges;
	int startEdge = 0;
	int inputNumNodes = 5;
	/// <summary>
	/// Сводка для FormApp
	/// </summary>
	public ref class FormApp : public System::Windows::Forms::Form
	{
	public:
		FormApp(void)
		{
			InitializeComponent();

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~FormApp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonLoadFile;
	protected:


	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ windowMatrix;

	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ nearestPath;

	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ buttonGenerateGraph;

	private: System::Windows::Forms::TextBox^ inputStartEdgeValue;

	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::Button^ solve;

	private: System::Windows::Forms::TextBox^ inputNumNodesValue;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnSaveResults;




	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonLoadFile = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->windowMatrix = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->nearestPath = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->buttonGenerateGraph = (gcnew System::Windows::Forms::Button());
			this->inputStartEdgeValue = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->solve = (gcnew System::Windows::Forms::Button());
			this->inputNumNodesValue = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSaveResults = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// buttonLoadFile
			// 
			this->buttonLoadFile->Location = System::Drawing::Point(71, 57);
			this->buttonLoadFile->Name = L"buttonLoadFile";
			this->buttonLoadFile->Size = System::Drawing::Size(191, 58);
			this->buttonLoadFile->TabIndex = 0;
			this->buttonLoadFile->Text = L"Загрузить из файла";
			this->buttonLoadFile->UseVisualStyleBackColor = true;
			this->buttonLoadFile->Click += gcnew System::EventHandler(this, &FormApp::buttonLoadFile_Click);
			// 
			// textBox1
			// 
			this->textBox1->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBox1->BackColor = System::Drawing::SystemColors::Control;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Location = System::Drawing::Point(71, 38);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(191, 13);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"Добавить граф";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &FormApp::textBox1_TextChanged);
			// 
			// windowMatrix
			// 
			this->windowMatrix->AcceptsReturn = true;
			this->windowMatrix->Location = System::Drawing::Point(517, 31);
			this->windowMatrix->Multiline = true;
			this->windowMatrix->Name = L"windowMatrix";
			this->windowMatrix->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->windowMatrix->Size = System::Drawing::Size(378, 197);
			this->windowMatrix->TabIndex = 4;
			this->windowMatrix->TextChanged += gcnew System::EventHandler(this, &FormApp::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBox3->BackColor = System::Drawing::SystemColors::Control;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Location = System::Drawing::Point(507, 12);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(378, 13);
			this->textBox3->TabIndex = 5;
			this->textBox3->Text = L"Матрица смежности";
			this->textBox3->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &FormApp::textBox3_TextChanged);
			// 
			// nearestPath
			// 
			this->nearestPath->Location = System::Drawing::Point(517, 284);
			this->nearestPath->Multiline = true;
			this->nearestPath->Name = L"nearestPath";
			this->nearestPath->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->nearestPath->Size = System::Drawing::Size(378, 152);
			this->nearestPath->TabIndex = 6;
			this->nearestPath->TextChanged += gcnew System::EventHandler(this, &FormApp::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBox5->BackColor = System::Drawing::SystemColors::Control;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Location = System::Drawing::Point(517, 265);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(378, 13);
			this->textBox5->TabIndex = 7;
			this->textBox5->Text = L"Кратчайшие пути";
			this->textBox5->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// buttonGenerateGraph
			// 
			this->buttonGenerateGraph->Location = System::Drawing::Point(71, 139);
			this->buttonGenerateGraph->Name = L"buttonGenerateGraph";
			this->buttonGenerateGraph->Size = System::Drawing::Size(191, 58);
			this->buttonGenerateGraph->TabIndex = 8;
			this->buttonGenerateGraph->Text = L"Сгенерировать граф";
			this->buttonGenerateGraph->UseVisualStyleBackColor = true;
			this->buttonGenerateGraph->Click += gcnew System::EventHandler(this, &FormApp::buttonGenerateGraph_Click);
			// 
			// inputStartEdgeValue
			// 
			this->inputStartEdgeValue->Location = System::Drawing::Point(284, 332);
			this->inputStartEdgeValue->Name = L"inputStartEdgeValue";
			this->inputStartEdgeValue->Size = System::Drawing::Size(127, 20);
			this->inputStartEdgeValue->TabIndex = 9;
			this->inputStartEdgeValue->Text = L"1";
			this->inputStartEdgeValue->TextChanged += gcnew System::EventHandler(this, &FormApp::textBox2_TextChanged_1);
			// 
			// textBox4
			// 
			this->textBox4->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->textBox4->BackColor = System::Drawing::SystemColors::Control;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Location = System::Drawing::Point(71, 332);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(191, 13);
			this->textBox4->TabIndex = 10;
			this->textBox4->Text = L"Начальная вершина";
			this->textBox4->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &FormApp::textBox4_TextChanged_1);
			// 
			// solve
			// 
			this->solve->Location = System::Drawing::Point(71, 358);
			this->solve->Name = L"solve";
			this->solve->Size = System::Drawing::Size(340, 23);
			this->solve->TabIndex = 11;
			this->solve->Text = L"Найти кратчайшие пути";
			this->solve->UseVisualStyleBackColor = true;
			this->solve->Click += gcnew System::EventHandler(this, &FormApp::solve_Click);
			// 
			// inputNumNodesValue
			// 
			this->inputNumNodesValue->Location = System::Drawing::Point(284, 166);
			this->inputNumNodesValue->Name = L"inputNumNodesValue";
			this->inputNumNodesValue->Size = System::Drawing::Size(127, 20);
			this->inputNumNodesValue->TabIndex = 12;
			this->inputNumNodesValue->Text = L"5";
			this->inputNumNodesValue->TextChanged += gcnew System::EventHandler(this, &FormApp::textBox6_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(281, 150);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 13);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Число вершин:";
			this->label1->Click += gcnew System::EventHandler(this, &FormApp::label1_Click);
			// 
			// btnSaveResults
			// 
			this->btnSaveResults->Location = System::Drawing::Point(517, 495);
			this->btnSaveResults->Name = L"btnSaveResults";
			this->btnSaveResults->Size = System::Drawing::Size(378, 23);
			this->btnSaveResults->TabIndex = 14;
			this->btnSaveResults->Text = L"Сохранить в файл";
			this->btnSaveResults->UseVisualStyleBackColor = true;
			this->btnSaveResults->Click += gcnew System::EventHandler(this, &FormApp::btnSaveResults_Click);
			// 
			// FormApp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1011, 588);
			this->Controls->Add(this->btnSaveResults);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->inputNumNodesValue);
			this->Controls->Add(this->solve);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->inputStartEdgeValue);
			this->Controls->Add(this->buttonGenerateGraph);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->nearestPath);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->windowMatrix);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->buttonLoadFile);
			this->Name = L"FormApp";
			this->Text = L"FormApp";
			this->Load += gcnew System::EventHandler(this, &FormApp::FormApp_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FormApp_Load(System::Object^ sender, System::EventArgs^ e) {
	}
		   vector<int> splitLine(const string& s, char delimiter) {
			   vector<int> tokens;
			   string token;
			   istringstream tokenStream(s);
			   while (getline(tokenStream, token, delimiter)) {
				   tokens.push_back(stoi(token));
			   }
			   return tokens;
		   }
		   vector<Edge> readFile(string fileName) {
			   vector<Edge> edges;

			   ifstream file(fileName);
			   if (!file.is_open()) {
				   cout << "errro";
				   return edges;
			   }

			   string str;
			   while (std::getline(file, str))
			   {
				   if (str.empty()) {
					   break;
				   }
				   vector<int> tempElems = splitLine(str, ' ');
				   edges.push_back(Edge{ tempElems[0] - 1, tempElems[1] - 1, tempElems[2] });
			   }
			   file.close();
			   return edges;
		   }


		   int getNumNodes(vector<Edge> edges) {
			   set<int> nodes;
			   for (auto& edge : edges) {
				   nodes.insert(edge.u);
				   nodes.insert(edge.v);
			   }
			   return nodes.size();
		   }

		   vector<string> buildAndConvertMatrixToSting(vector<Edge> edges) {
			   int numEdges = edges.size();
			   int numNodes = getNumNodes(edges);

			   int** A = new int* [numNodes];
			   for (int i = 0; i < numNodes; i++) {
				   A[i] = new int[numNodes];
			   }
			   for (int i = 0; i < numNodes; i++)
			   {
				   for (int j = 0; j < numNodes; j++) {
					   A[i][j] = 0;
				   }
			   }
			   for (int i = 0; i < edges.size(); i++) {
				   A[edges[i].u][edges[i].v] = edges[i].w;
			   }

			   vector<string> rows;
			   for (int i = 0; i < numNodes; i++)
			   {
				   string tempStr;
				   for (int j = 0; j < numNodes; j++) {
					   tempStr += to_string(A[i][j]) + ' ';
				   }
				   rows.push_back(tempStr);
			   }

			   return rows;
		   }


		   AlgoritmResults BellmanFordAlgoritm(vector<Edge> edges, int src) {

			   int numEdges = edges.size();
			   int numNodes = getNumNodes(edges);

			   // init distance vector
			   vector<int> dist(numNodes, INF);
			   dist[src] = 0;

			   vector<int> edgePath(numNodes, -1);

			   for (int i = 0; i <= numNodes - 1; i++) {
				   bool change = false;
				   for (int j = 0; j < numEdges; j++) {
					   //d[e[j].a] < INF
					   if (dist[edges[j].u] < INF) {
						   if (dist[edges[j].u] + edges[j].w < dist[edges[j].v]) {
							   dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
							   edgePath[edges[j].v] = edges[j].u;
							   change = true;
						   }
					   }
				   }
				   if (!change) {
					   break;
				   }
			   }

			   return AlgoritmResults{ dist, edgePath };
		   }


		   string getEdgePath(vector<int> dist, vector<int> edgePath, int startEdge, int endEdge) {
			   vector<int> path;
			   string strPath;
			   if (dist[endEdge] == INF) {
				   strPath = "Отсутствует путь " + to_string(startEdge + 1) + " до " + to_string(endEdge + 1) + ".";
				   return strPath;
			   }

			   for (int cur = endEdge; cur != -1; cur = edgePath[cur]) {
				   for (size_t i2 = 0; i2 < path.size(); i2++) {
					   if (cur == path[i2] && path.size() > 1) {
						   path.push_back(cur);
						   reverse(path.begin(), path.end());

						   for (auto& el : path) {
							   strPath += to_string(el + 1) + " ";
						   }
						   strPath = "Отрицательный цикл: " + to_string(startEdge + 1) + " до " + to_string(endEdge + 1) + " со стоимостью " + to_string(dist[endEdge]) + " : " + strPath;
						   return strPath;
					   }
				   }
				   path.push_back(cur);
			   }

			   reverse(path.begin(), path.end());
			   for (auto& el : path) {
				   strPath += to_string(el + 1) + " ";
			   }
			   strPath = "Путь от " + to_string(startEdge + 1) + " до " + to_string(endEdge + 1) + " со стоимостью " + to_string(dist[endEdge]) + " : " + strPath;

			   return strPath;
		   }

		   vector<string> getAllShortestPath(vector<int> dist, vector<int> edgePath, int startEdge) {
			   vector<string> rows;

			   for (int endEdge = 0; endEdge < dist.size(); endEdge++) {
				   if (endEdge == startEdge)
					   continue;
				   string tmpPath = getEdgePath(dist, edgePath, startEdge, endEdge);
				   rows.push_back(tmpPath);
			   }

			   return rows;
		   }

		   vector<Edge> generateGraph(int numNodes) {
			   int** A = new int* [numNodes];
			   for (int i = 0; i < numNodes; i++) {
				   A[i] = new int[numNodes];
			   }
			   for (int i = 0; i < numNodes; i++)
			   {
				   for (int j = 0; j < numNodes; j++) {
					   A[i][j] = 0;
				   }
			   }
			   srand(time(NULL));
			   int ch = 0;
			   int ch2 = 0;

			   for (int i = 0; i < numNodes - 1; i++) // генерация матрицы M1 (взвешанный ориентированный граф)
			   {
				   A[i][i] = 0;
				   //for (int j = i + 1; j < numNodes; j++)
				   for (int j = 0; j < numNodes; j++)
				   {
					   ch = rand() % 15;
					   ch2 = rand() % 100;
					   if (ch < 12)
					   {
						   if (ch > 9)
							   ch = ch - 6;

						   if (ch2 < 1)
							   ch = -ch;

						   A[i][j] = ch;
						   A[j][i] = 0;
					   }
					   else
					   {
						   A[i][j] = 0;
					   }
				   }
			   }

			   vector<Edge> edges;
			   for (int i = 0; i < numNodes; i++) {
				   for (int j = 0; j < numNodes; j++) {
					   if (A[i][j] != 0) {
						   edges.push_back(Edge{ i, j, A[i][j] });
					   }
				   }
			   }

			   return edges;
		   }

	private: System::Void buttonGenerateGraph_Click(System::Object^ sender, System::EventArgs^ e) {
		this->windowMatrix->Text = "";
		this->nearestPath->Text = "";

		String^ textInputNumNodes = this->inputNumNodesValue->Text;
		string strInputNumNodes = msclr::interop::marshal_as<string>(textInputNumNodes);
		inputNumNodes = atoi(strInputNumNodes.c_str());

		edges = generateGraph(inputNumNodes);
		vector<string> rows = buildAndConvertMatrixToSting(edges);

		for (int i = 0; i < rows.size(); i++) {
			String^ StringRowMatrix = msclr::interop::marshal_as<String^>(rows[i].c_str());
			this->windowMatrix->Text += StringRowMatrix + "\r\n";
		}

	}
	private: System::Void buttonLoadFile_Click(System::Object^ sender, System::EventArgs^ e) {
		this->windowMatrix->Text = "";
		this->nearestPath->Text = "";

		Stream^ myStream;
		OpenFileDialog^ fileDialog = gcnew OpenFileDialog;

		if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if ((myStream = fileDialog->OpenFile()) != nullptr) {
				String^ fileNameStream = fileDialog->FileName;

				std::string fileName = msclr::interop::marshal_as< std::string >(fileNameStream);

				edges = readFile(fileName);
				vector<string> rows = buildAndConvertMatrixToSting(edges);
				for (int i = 0; i < rows.size(); i++) {
					String^ StringRowMatrix = msclr::interop::marshal_as<String^>(rows[i].c_str());
					this->windowMatrix->Text += StringRowMatrix + "\r\n";
				}
				myStream->Close();
			}

		}
	}
	private: System::Void btnSaveResults_Click(System::Object^ sender, System::EventArgs^ e) {
		string fileName;
		Stream^ myStream;
		SaveFileDialog^ fileDialog = gcnew SaveFileDialog;

		if (fileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if ((myStream = fileDialog->OpenFile()) != nullptr) {
				String^ fileNameStream = fileDialog->FileName;
				fileName = msclr::interop::marshal_as< std::string >(fileNameStream);
				myStream->Close();
			}
		}

		ofstream out(fileName);
		if (out.is_open())
		{
			out << "Матрица смежности: " << endl;
			string matrix = msclr::interop::marshal_as< std::string >(windowMatrix->Text);
			out << matrix << endl;

			out << "Кратчайшие пути: " << endl;
			string nearestPathes = msclr::interop::marshal_as< std::string >(nearestPath->Text);
			out << nearestPathes << endl;

		}
		out.close();
	}

	private: System::Void solve_Click(System::Object^ sender, System::EventArgs^ e) {
		this->nearestPath->Text = "";

		String^ inpStartEdgeValue = inputStartEdgeValue->Text;
		string inpStartEdge = msclr::interop::marshal_as<string>(inpStartEdgeValue);
		startEdge = atoi(inpStartEdge.c_str());
		int numEdges = getNumNodes(edges);
		if (startEdge < 1 || startEdge > numEdges) {
			this->nearestPath->Text = "Указанной выершины нет в графе.";
			return;
		}
		startEdge = startEdge - 1;

		AlgoritmResults out = BellmanFordAlgoritm(edges, startEdge);
		vector<string> pathList = getAllShortestPath(out.distances, out.edgePath, startEdge);
		for (int i = 0; i < pathList.size(); i++) {
			String^ StringRowMatrix = msclr::interop::marshal_as<String^>(pathList[i].c_str());
			this->nearestPath->Text += StringRowMatrix + "\r\n";
		}
	}

	private: System::Void textBox4_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonGraphInput_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox6_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	};
}




