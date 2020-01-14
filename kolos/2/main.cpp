/**
 * Zadanie 2.
 * Napisać program z listą uczniów w klasie przy pomocy kontenera zbioru.
 * Program powinien umożliwić umieszczenie w pojemniku następujących danych:
 * - Imię, nazwisko, id osoby,
 * - Usunąć ucznia ze zbioru, wyświetlać listę uczniów
 */

#include <wx/wx.h>
#include <wx/listctrl.h>
#include <set>
#include <string>
#include <iostream>

struct student_t {
    int id;
    std::string imie, nazwisko;
    public:
    bool operator<(const student_t& other) const {
        return id < other.id;
    }
};

class my_frame : public wxFrame {
    std::set<student_t> student_set;

    wxListCtrl* list;
    wxTextCtrl *imie_ctrl, *nazwisko_ctrl, *do_usuniecia;

    public:
    void draw() {
        list->ClearAll();
        for (auto& st : student_set) {
            list->InsertItem(
                0, std::to_string(st.id) + " " + st.imie + " " + st.nazwisko
            );
        }
        list->Update();
    }

    my_frame() {
        Create(nullptr, wxNewId(), "Lista uczniów",
               wxDefaultPosition, {400, 600});

        auto sizer = new wxBoxSizer{wxVERTICAL};

        list = new wxListCtrl{this};
        sizer->Add(list, wxSizerFlags(1).Expand());

        imie_ctrl = new wxTextCtrl{this, wxNewId(), "nowe imie"};
        nazwisko_ctrl = new wxTextCtrl{this, wxNewId(), "nowe nazwisko"};
        sizer->Add(imie_ctrl, wxSizerFlags(0).Expand());
        sizer->Add(nazwisko_ctrl, wxSizerFlags(0).Expand());

        auto button = new wxButton{this, wxNewId(), "dodaj"};
        sizer->Add(button, wxSizerFlags(0).Expand());

        button->Bind(wxEVT_BUTTON, [this](wxEvent& event) {
            student_t nowy;
            int id = 0;
            for (auto& student : student_set) {
                if (student.id > id) id = student.id;
            }
            nowy.id = id + 1;
            nowy.imie = imie_ctrl->GetValue().ToStdString();
            nowy.nazwisko = nazwisko_ctrl->GetValue().ToStdString();
            student_set.insert(nowy);
            std::cout << "dodano " << nowy.nazwisko << std::endl;

            draw();
        });

        do_usuniecia = new wxTextCtrl{this, wxNewId(), "id do usuniecia"};
        sizer->Add(do_usuniecia, wxSizerFlags(0).Expand());

        auto usun = new wxButton{this, wxNewId(), "usun"};
        sizer->Add(usun, wxSizerFlags(0).Expand());
        usun->SetBackgroundColour({255, 200, 200});

        usun->Bind(wxEVT_BUTTON, [this](wxEvent& event) {
            long id;
            if (do_usuniecia->GetValue().ToLong(&id)) {
                for (auto& st : student_set) {
                    if (st.id == id)  {
                        student_set.erase(st);
                        draw();
                        return;
                    }
                }
            } else {
                student_set.clear();
                draw();
            }
        });

        SetSizerAndFit(sizer);
    }
};

class my_app : public wxApp {
    public:
    bool OnInit() {
        auto frame = new my_frame;
        frame->Show();
        return true;
    }
};

wxIMPLEMENT_APP(my_app);