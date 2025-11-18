#pragma once
#include <cmath>   // бібліотека математичних функцій

namespace Lab1Function {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        Label^ label1;
        Label^ label2;
        Label^ label3;

        TextBox^ textBox1;
        TextBox^ textBox2;
        TextBox^ textBox3;

        Button^ button1;
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            // Компоненти
            this->label1 = (gcnew Label());
            this->label2 = (gcnew Label());
            this->label3 = (gcnew Label());

            this->textBox1 = (gcnew TextBox());
            this->textBox2 = (gcnew TextBox());
            this->textBox3 = (gcnew TextBox());

            this->button1 = (gcnew Button());

            this->SuspendLayout();

            // label1 – заголовок X
            this->label1->Text = L"Введіть x:";
            this->label1->Location = System::Drawing::Point(10, 20);

            // label2 – заголовок результату
            this->label2->Text = L"Результат y:";
            this->label2->Location = System::Drawing::Point(10, 60);

            // label3 – опис формули
            this->label3->Text = L"y = sqrt(|x - 1|) + sin(x)";
            this->label3->Location = System::Drawing::Point(10, 100);
            this->label3->AutoSize = true;

            // textBox1 – введення x
            this->textBox1->Location = System::Drawing::Point(120, 20);
            this->textBox1->Size = System::Drawing::Size(120, 22);

            // textBox2 – поле результату
            this->textBox2->Location = System::Drawing::Point(120, 60);
            this->textBox2->Size = System::Drawing::Size(120, 22);

            // textBox3 – додаткове поле (як у методичці)
            this->textBox3->Location = System::Drawing::Point(10, 140);
            this->textBox3->Size = System::Drawing::Size(230, 22);

            // button1 – “Обчислити”
            this->button1->Text = L"Обчислити";
            this->button1->Location = System::Drawing::Point(10, 180);
            this->button1->Click += gcnew EventHandler(this, &Form1::button1_Click);

            // Налаштування форми
            this->ClientSize = System::Drawing::Size(260, 230);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->button1);
            this->Text = L"Обчислення функції";

            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        // Обробник кнопки "Обчислити"
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
    {
        try
        {
            // Зчитування X з текстового поля (перетворення string → double)
            double x = Convert::ToDouble(textBox1->Text);

            // Обчислення y = sqrt(|x – 1|) + sin(x)
            double y = std::sqrt(std::fabs(x - 1)) + std::sin(x);

            // Виведення результату
            textBox2->Text = Convert::ToString(y);

            // Додатковий коментар (опціонально)
            textBox3->Text = L"Обчислення виконано успішно.";
        }
        catch (...)
        {
            textBox3->Text = L"Помилка: введіть коректне число.";
        }
    }
    };
}