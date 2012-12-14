#pragma once

#include "basic.h"
#include "Mytree.h"
#include "AVL.h"
#include "Btree.h"
#include "treap.h"
#include "BST.h" 

BST<int> bst;
AVL<int> avl;
Treap<int> treap;
Btree<int> btree;
Mytree<int> *trees[] = { &bst, &avl, &treap, &btree };
	
#include "test.h"

Test test;

#define handle(p1,p2,p3)											\
{																	\
	is_testing = false;												\
	String^ tmp = this->p1->Text->ToString();						\
	if (!isnum(tmp))												\
	{																\
		return;														\
	}																\
	int key = System::Convert::ToInt32(tmp);						\
	bool sig = trees[this->comboBox1->SelectedIndex]->p2(key);		\
	if (!sig) MessageBox::Show(p3);									\
	trees[this->comboBox1->SelectedIndex]->tranverse();				\
	this->pictureBox1->Refresh();									\
}														

namespace Tree {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Form1 摘要
	///
	/// 警告: 如果更改此类的名称，则需要更改
	///          与此类所依赖的所有 .resx 文件关联的托管资源编译器工具的
	///          “资源文件名”属性。否则，
	///          设计器将不能与此窗体的关联
	///          本地化资源正确交互。
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			cnt = 0;
			is_testing = false;
			InitializeComponent();
			//
			//TODO: 在此处添加构造函数代码
			//
		}

	protected:
		/// <summary>
		/// 清理所有正在使用的资源。
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
				
			}
		}

	private: System::Windows::Forms::Button^  button1;





	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::MaskedTextBox^  maskedTextBox2;
	private: System::Windows::Forms::ComboBox^  comboBox1;


	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::OpenFileDialog^  openfiledialog;

	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::PictureBox^  pictureBox1;








	protected: 

	private:
		/// <summary>
		/// 必需的设计器变量。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 设计器支持所需的方法 - 不要
		/// 使用代码编辑器修改此方法的内容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox1 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->maskedTextBox2 = (gcnew System::Windows::Forms::MaskedTextBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->openfiledialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(94, 109);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(64, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L" 插入";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::Button1_Click);
			// 
			// maskedTextBox1
			// 
			this->maskedTextBox1->Location = System::Drawing::Point(19, 110);
			this->maskedTextBox1->Name = L"maskedTextBox1";
			this->maskedTextBox1->Size = System::Drawing::Size(62, 25);
			this->maskedTextBox1->TabIndex = 7;
			this->maskedTextBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::maskedTextBox1_KeyDown);
			this->maskedTextBox1->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Form1::maskedTextBox1_MaskInputRejected);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(94, 150);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(64, 25);
			this->button2->TabIndex = 8;
			this->button2->Text = L"删除";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::Button2_Click);
			// 
			// maskedTextBox2
			// 
			this->maskedTextBox2->Location = System::Drawing::Point(19, 150);
			this->maskedTextBox2->Name = L"maskedTextBox2";
			this->maskedTextBox2->Size = System::Drawing::Size(62, 25);
			this->maskedTextBox2->TabIndex = 9;
			this->maskedTextBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::maskedTextBox2_KeyDown);
			this->maskedTextBox2->MaskInputRejected += gcnew System::Windows::Forms::MaskInputRejectedEventHandler(this, &Form1::maskedTextBox2_MaskInputRejected);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"BST", L"AVL", L"Treap", L"Btree"});
			this->comboBox1->Location = System::Drawing::Point(24, 212);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 23);
			this->comboBox1->TabIndex = 10;
			this->comboBox1->Text = L"BST";
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->checkBox1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->button5);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->button4);
			this->groupBox1->Controls->Add(this->button3);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->maskedTextBox1);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->maskedTextBox2);
			this->groupBox1->Controls->Add(this->button2);
			this->groupBox1->Location = System::Drawing::Point(920, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(164, 616);
			this->groupBox1->TabIndex = 12;
			this->groupBox1->TabStop = false;
			this->groupBox1->Enter += gcnew System::EventHandler(this, &Form1::groupBox1_Enter);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(92, 484);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(53, 19);
			this->checkBox1->TabIndex = 22;
			this->checkBox1->Text = L"BST";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(33, 555);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(84, 15);
			this->label4->TabIndex = 1;
			this->label4->Text = L"计算机0907";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(16, 525);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(125, 15);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Powered by 何剑";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(2, 313);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(82, 15);
			this->label3->TabIndex = 19;
			this->label3->Text = L"数据类型：";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 279);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 15);
			this->label2->TabIndex = 18;
			this->label2->Text = L"(最多100万)";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 254);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 15);
			this->label1->TabIndex = 17;
			this->label1->Text = L"数据个数:";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(87, 251);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(67, 25);
			this->textBox2->TabIndex = 16;
			this->textBox2->Text = L"100000";
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &Form1::textBox2_TextChanged);
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"随机型", L"顺序型", L"逆序型"});
			this->comboBox2->Location = System::Drawing::Point(20, 343);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(121, 23);
			this->comboBox2->TabIndex = 15;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(36, 372);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(105, 23);
			this->button5->TabIndex = 14;
			this->button5->Text = L"生成测试文件";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(20, 410);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(121, 25);
			this->textBox1->TabIndex = 13;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(9, 480);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(66, 23);
			this->button4->TabIndex = 12;
			this->button4->Text = L"测试";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(36, 441);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(89, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"打开文件";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				170)));
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(1087, 622);
			this->tableLayoutPanel1->TabIndex = 13;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tableLayoutPanel1_Paint);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(911, 616);
			this->panel1->TabIndex = 11;
			// 
			// openfiledialog
			// 
			this->openfiledialog->DefaultExt = L"txt";
			this->openfiledialog->FileName = L"input.txt";
			this->openfiledialog->Filter = L"文本文件(*.txt)|*.txt|所有文件(*.*)|*.*";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(4000, 4000);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::DrawCircle);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(21, 45);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(127, 15);
			this->label6->TabIndex = 23;
			this->label6->Text = L"树演示与测试系统";
			this->label6->Click += gcnew System::EventHandler(this, &Form1::label6_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1087, 622);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private:
		int cnt; bool is_testing;
		
		System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			this->comboBox2->SelectedIndex = 0;
		}
		bool isnum(String^ a)
		{
			if (a->Length == 0) return false;
			for (int i=0;i<a->Length;i++)
			if (!(a[i] <= '9' && a[i] >= '0'))
				return false;
			return true;
		}
		System::Void Button1_Click(System::Object^  sender, System::EventArgs^  e) handle(maskedTextBox1, insert, "该数已存在");
		System::Void Button2_Click(System::Object^  sender, System::EventArgs^  e) handle(maskedTextBox2, erase, "该数不存在");
		void DrawCircle(Object^ sender, PaintEventArgs^ e )
		{
			if (is_testing){
				DrawResult(sender, e);
				return;
			}
			if(this->comboBox1->SelectedIndex == 3) {
				DrawBtree(sender, e);
				return;
			}
			Graphics^ g = e->Graphics;
			// Create pen.
			Pen^ pen = gcnew Pen(Color::Red, 2.0f);

			for (size_t i=0;i<edge.size();i++)
			{
				int a = edge[i].first;
				int b = edge[i].second;
				g->DrawLine(pen, Point(circle[a].x, circle[a].y), Point(circle[b].x, circle[b].y));
			}

			for (int i=0;i<tot_ID;i++)
			{	
				// Create rectangle for ellipse.
				Rectangle rect = Rectangle(circle[i].x-Radius, circle[i].y-Radius, 2*Radius, 2*Radius);
				// Draw ellipse to screen.
				g->DrawEllipse(pen, rect);
				if (circle[i].key == Convert::ToInt32(this->maskedTextBox1->Text))
					g->FillEllipse(System::Drawing::Brushes::DarkGray, rect); 
				else
					g->FillEllipse(System::Drawing::Brushes::DarkOliveGreen, rect);
				if (this->comboBox1->SelectedIndex == 2)
				{
					g->DrawString(circle[i].key.ToString(),
						gcnew System::Drawing::Font( "Arial",8 ), System::Drawing::Brushes::White, Point(circle[i].x-Radius/2,circle[i].y) );			
					g->DrawString(circle[i].key2.ToString(),
						gcnew System::Drawing::Font( "Arial",6 ), System::Drawing::Brushes::Yellow, Point(circle[i].x-Radius/2,circle[i].y-Radius/2) );	
				}else
					g->DrawString(circle[i].key.ToString(),
						gcnew System::Drawing::Font( "Arial",8 ), System::Drawing::Brushes::White, Point(circle[i].x-Radius/2,circle[i].y-Radius/4) );		
			}
		}
		void DrawBtree(Object^ /*sender*/, PaintEventArgs^ e )
		{
			Graphics^ g = e->Graphics;
			Pen^ mypen = gcnew Pen( Color::Red,2.0f );
			for (int i=0;i<tot_ID;i++)
			{
				BtreeRect &now = btreeRect[i];
				Rectangle rect = Rectangle(now.x, now.y, RECT_LENGTH_X*now.size, RECT_LENGTH_Y); 
				//MessageBox::Show("now is " + now.x.ToString() + " " + now.y.ToString() + " " + RECT_LENGTH_X.ToString() + " " + RECT_LENGTH_Y.ToString());				
				int lx = now.x;
				if (!now.leaf)
				{
					for (int j=1;j<=now.size+1;j++)
					{
						BtreeRect &u = btreeRect[ now.son[j] ];
						int centrex = (u.x + u.x + RECT_LENGTH_X*u.size) / 2;
						//int nowx = now.x + (j-1)*RECT_LENGTH_X;
						g->DrawLine(mypen, Point(centrex, u.y), Point(lx, now.y + RECT_LENGTH_Y)); 
						if (j <= now.size)
							lx += NUM_GAP + now.key[j].ToString()->Length*8;									
					}
				}
				//g->DrawRectangle(mypen, rect);
				//g->FillRectangle(System::Drawing::Brushes::DarkGreen, rect);
				lx = now.x;
				for (int j=1;j<=now.size;j++)
				{
					String^ tmp = now.key[j].ToString();
					if (this->maskedTextBox1->Text->ToString() == now.key[j].ToString())
						g->FillRectangle(System::Drawing::Brushes::DarkGray, lx, now.y, NUM_GAP+tmp->Length*8, RECT_LENGTH_Y);
					else
						g->FillRectangle(System::Drawing::Brushes::DarkGreen, lx, now.y, NUM_GAP+tmp->Length*8, RECT_LENGTH_Y); 
					
					g->DrawString(now.key[j].ToString(),
						gcnew System::Drawing::Font( "Arial",8 ), System::Drawing::Brushes::White, Point(lx+3, now.y+RECT_LENGTH_Y/3) );		
					lx += NUM_GAP+tmp->Length*8;					
				}
				g->DrawRectangle(mypen, now.x, now.y, lx-now.x, RECT_LENGTH_Y);
			}
		}
		void DrawResult(Object^ /*sender*/, PaintEventArgs^ e )
		{
			array<String^>^ tree_name = {"BST", "Treap", "AVL", "Btree"};
			array<String^>^ operation_name = {"InsertTime", "QueryTime", "EraseTime", "TotalTime"};
			Graphics^ g = e->Graphics;
			array<Brush^>^ color = {Brushes::Blue, Brushes::Red, Brushes::Green, Brushes::DarkGray};
			
			Pen^ blackpen = gcnew Pen(Color::Black);
			

			int BOTTOM_Y = 0;
			for (int run=0;run<3;run++)
				for (int i=0;i<4;i++)	
					BOTTOM_Y = max(BOTTOM_Y, test.Time[run][i]);
			BOTTOM_Y += 100;

			int LX = 100;		
			g->DrawLine(blackpen, LX-30, BOTTOM_Y, 1000, BOTTOM_Y);
			g->DrawLine(blackpen, LX-30, BOTTOM_Y, LX-30, 50);
			for (int h=BOTTOM_Y; h>50; h-=100)
			{
				g->DrawString((BOTTOM_Y-h).ToString(), gcnew System::Drawing::Font( "Arial",8 ), Brushes::Black, Point(LX-60, h));		
			}	
			g->DrawString("t/ms", gcnew System::Drawing::Font( "Arial",8 ), Brushes::Black, Point(LX-60, 42));

			for (int run=0;run<3;run++)
			{
				for (int i=0;i<4;i++)								
				{													
					Rectangle rect = Rectangle(LX , BOTTOM_Y-test.Time[run][i], RESULT_WIDTH, test.Time[run][i]);				 				
					g->FillRectangle(color[i], rect);	
					g->DrawString(tree_name[i],
						gcnew System::Drawing::Font( "Arial",8 ), System::Drawing::Brushes::Black, Point(LX, BOTTOM_Y+10));		
					LX += RESULT_WIDTH;														
				}	
				g->DrawString(operation_name[run],
							gcnew System::Drawing::Font( "Arial",8 ), System::Drawing::Brushes::Black, Point(LX-3*RESULT_WIDTH, BOTTOM_Y+30));			
				LX += RESULT_GAP;		
			}
			//drawresult(Insert_Time);
			//drawresult(Query_Time);
			//drawresult(Erase_Time);	
		}
private: System::Void maskedTextBox1_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		 }
private: System::Void maskedTextBox2_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
		 }
private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 for (int p=0;p<4;p++) trees[p]->clear();
		 }
private: System::Void maskedTextBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			 if (e->KeyCode == Keys::Enter)
				Button1_Click(sender, e);
		 }
private: System::Void maskedTextBox2_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
			if (e->KeyCode == Keys::Enter)
				Button2_Click(sender, e);
		 }
private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		 }
private: void MarshalString ( String ^ s, string& os ) 
		 {
				using namespace Runtime::InteropServices;
				const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
				os = chars;
				Marshal::FreeHGlobal(IntPtr((void*)chars));
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("测试文件格式为\n 第一行N M T分别表示插入，查询，删除数目\n 后三行分别为N,M,T个数");
			 this->openfiledialog->ShowDialog();
			 this->textBox1->Text = this->openfiledialog->FileName;
		 }

private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
		 	 
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		 	 String^ FileName = this->openfiledialog->FileName;
			 string filename;
			 MarshalString(FileName, filename);
			 test.FileTest(filename, this->checkBox1->Checked);
			 is_testing = true;
			 this->pictureBox1->Refresh();
		 }
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
			 MessageBox::Show("数据文件放在当前目录下的input.txt");
			 test.GenerateCase(Convert::ToInt32(this->textBox2->Text->ToString()), this->comboBox2->SelectedIndex);
		 }
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

