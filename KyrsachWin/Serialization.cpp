#include "Serialization.h"

void MarshalString(String^ s, std::string& os) {
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
}

std::string ToStr(String^ s) {
    std::string os;
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    return os;
}
json Serialization::save_passport_data(Passport_data^ Passport) {
    std::string filename = "employee_passport_info.json";
    json j;

    // Чтение существующих данных из файла
  /*  try {*/
        //std::ifstream file_read(filename);
        //if (file_read.is_open()) {
        //    file_read >> j;
        //    file_read.close();
        //    std::cout << "Existing JSON data read successfully." << std::endl;
        //}
        //else {
        //    // Если файл не существует или не может быть открыт, создаем новый объект JSON
        //    j = json::object();
        //    j["passports_date"] = json::array();
        //    std::cout << "File not found or unable to open, creating new JSON object." << std::endl;
        //}
  /*  }
    catch (const std::exception& e) {
        std::cerr << "Error reading JSON file: " << e.what() << std::endl;
       
    }*/

    msclr::interop::marshal_context context;

    std::string surname = context.marshal_as<std::string>(Passport->get_surname());
    std::string name = context.marshal_as<std::string>(Passport->get_name());
    std::string patronymic = context.marshal_as<std::string>(Passport->get_patronymic());
    std::string sex = context.marshal_as<std::string>(Passport->get_sex());
    std::string date_of_birthday = context.marshal_as<std::string>(Passport->get_date_of_birthday());
    std::string nationality = context.marshal_as<std::string>(Passport->get_nationality());
    std::string family_status = context.marshal_as<std::string>(Passport->get_family_status());
    std::string ipn = context.marshal_as<std::string>(Passport->get_ipn());
    std::string adres = context.marshal_as<std::string>(Passport->get_adres());

    // Додавання нового користувача
    json new_user = {
        {"Surname", surname},
        {"Name", name},
        {"Patronymic", patronymic},
        {"Sex", sex},
        {"Date of birthday", date_of_birthday},
        {"Nationality", nationality},
        {"Family status", family_status},
        {"IPN", ipn},
        {"adres", adres}
    };
    return new_user;
    // Додавання нового користувача до масиву
    //j["passports"].push_back(new_user);
    //std::cout << "New user added to JSON data: " << new_user.dump(4) << std::endl;

    //// Запись измененных данных обратно в файл
    //try {
    //    std::ofstream file_write(filename);
    //    if (file_write.is_open()) {
    //        file_write << j.dump(4);  // Запись с отступами для лучшей читаемости
    //        file_write.close();
    //        std::cout << "Data successfully written to " << filename << std::endl;
    //        std::cout << "New JSON data: " << j.dump(4) << std::endl;
    //    }
    //    else {
    //        std::cerr << "Unable to open JSON file for writing" << std::endl;
    //    }
    //}
    //catch (const std::exception& e) {
    //    std::cerr << "Error writing to JSON file: " << e.what() << std::endl;
    //}
}

//void Serialization::save_family_status(Family_status^ family) {
//    std::string filename = "employee_family_info.json";
//    json j;
//
//    // Чтение существующих данных из файла
//    try {
//        std::ifstream file_read(filename);
//        if (file_read.is_open()) {
//            file_read >> j;
//            file_read.close();
//            std::cout << "Existing JSON data read successfully." << std::endl;
//        }
//        else {
//            // Если файл не существует или не может быть открыт, создаем новый объект JSON
//            j = json::object();
//            j["family_date"] = json::array();
//            std::cout << "File not found or unable to open, creating new JSON object." << std::endl;
//        }
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error reading JSON file: " << e.what() << std::endl;
//        return;
//    }
//
//    msclr::interop::marshal_context context;
//
//    std::string stats = context.marshal_as<std::string>(family->get_family_stats());
//    std::string members = context.marshal_as<std::string>(family->get_family_members());
//
//
//    // Додавання нового користувача
//    json new_user = {
//        {"Family status", stats},
//        {"Family members", members}
//
//    };
//
//    // Додавання нового користувача до масиву
//    j["family_dates"].push_back(new_user);
//    std::cout << "New user added to JSON data: " << new_user.dump(4) << std::endl;
//
//    // Запись измененных данных обратно в файл
//    try {
//        std::ofstream file_write(filename);
//        if (file_write.is_open()) {
//            file_write << j.dump(4);  // Запись с отступами для лучшей читаемости
//            file_write.close();
//            std::cout << "Data successfully written to " << filename << std::endl;
//            std::cout << "New JSON data: " << j.dump(4) << std::endl;
//        }
//        else {
//            std::cerr << "Unable to open JSON file for writing" << std::endl;
//        }
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error writing to JSON file: " << e.what() << std::endl;
//    }
//    
//}

json Serialization::save_education( _education^ education)
{   
    json new_ed;
    for (int i = 0; i < education->get_list()->Count; i++)
    {
        new_ed.push_back({ { "name", ToStr(education->get_list()[i]->get_name())},
            {"education_level", ToStr(education->get_list()[i]->get_education_level())},
            {"diplom", ToStr(education->get_list()[i]->get_diploma())},
            {"graduation_year", ToStr(education->get_list()[i]->get_graduation_year())},
            {"science", ToStr(education->get_list()[i]->get_science())}
            });
    }



    // Додавання нового користувача
    json new_user = {
        {"inf", new_ed}
    };

    return new_user;
   
}

json Serialization::save_military_registration(military_registration^ military)
{
    try
    {
        //std::string filename = "employee_military_registration.json";
        //std::ifstream file_read(filename);
        //json j;

        //if (file_read.is_open()) {
        //    // Завантаження існуючих даних
        //    file_read >> j;
        //    file_read.close();
        //}

       /* std::string rank = ToStr(military->get_rank());
        std::string position = ToStr(military->get_position());
        int military_experience = military->get_military_experience();
        std::string suitability = ToStr(military->get_suitability() ? "+" : "-");*/


        // Додавання нового користувача
        json new_user = {
            {"rank", ToStr(military->get_rank())},
            {"position", ToStr(military->get_position())},
            {"military_experience", military->get_military_experience()},
            {"suitability", ToStr(military->get_suitability() ? "+" : "-")}
        };

        /*json new_user = {
           {"rank", rank},
           {"position", position},
           {"military_experience", military_experience},
           {"suitability", suitability}

        };*/

        // Додавання нового користувача до масиву
        //j["employee_military"].push_back(new_user);

        // Запис змінених даних назад у файл
        //std::ofstream file_write(filename);
        //if (file_write.is_open()) {
        //    file_write << j.dump(4);  // Запис з відступами для кращої читабельності
        //    file_write.close();
        //}

        //std::cout << "Military registration JSON: " << new_user.dump(4) << std::endl;

        return new_user;
    }
    catch (const std::exception& e) {
        std::cerr << "Error in save_military_registration: " << e.what() << std::endl;
        return json();
    }
}

json Serialization::save_health( Health^ health)
{
    //std::string filename = "employee_military_registration.json";
    //std::ifstream file_read(filename);
    //json j;

    //if (file_read.is_open()) {
    //    // Завантаження існуючих даних
    //    file_read >> j;
    //    file_read.close();
    //}
    
     // Додавання нового користувача
    

    json new_diseases;
    for (int i = 0; i < health->get_diseases()->Count; i++)
    {
        new_diseases.push_back({ { "name", ToStr(health->get_diseases()[i]->get_name())},
            {"type", ToStr(health->get_diseases()[i]->get_type())},
            {"disability_group", ToStr(health->get_diseases()[i]->get_disability_group())},
            });


    }

    json new_user = {
        {"state_of_health", ToStr(health->get_state_of_health())},
        {"diseases", new_diseases},
        {"blood_type", ToStr(health->get_blood_type())}
    };
   


    //// Додавання нового користувача до масиву
    //j["employee_health"].push_back(new_user);

    //// Запис змінених даних назад у файл
    //std::ofstream file_write(filename);
    //if (file_write.is_open()) {
    //    file_write << j.dump(4);  // Запис з відступами для кращої читабельності
    //    file_write.close();
    //}
    return new_user;
}

json Serialization::save_work(_work^ work)
{
    //std::string filename = "employee_military_registration.json";
    //std::ifstream file_read(filename);
    //json j;

    //if (file_read.is_open()) {
    //    // Завантаження існуючих даних
    //    file_read >> j;
    //    file_read.close();
    //}

    //// Додавання нового користувача
    //json new_user = {
    //    {"work_experience", ToStr(work->get_work_experience())},
    //    {"last_place_of_work_position", ToStr(work->get_last_place_of_work_position())},
    //    {"information_about_past_work", ToStr(work->get_information_about_past_work())},
    //    {"place_of_actual_redence", ToStr(work->get_place_of_actual_redence())}
    //};

    //// Додавання нового користувача до масиву
    //j["employee_work"].push_back(new_user);

    //// Запис змінених даних назад у файл
    //std::ofstream file_write(filename);
    //if (file_write.is_open()) {
    //    file_write << j.dump(4);  // Запис з відступами для кращої читабельності
    //    file_write.close();
    //}

    //std::string filename = "employee_work_history.json";
    //json j;

    //// Чтение существующих данных из файла
    //try {
    //    //std::ifstream file_read(filename);
    //    //if (file_read.is_open()) {
    //    //    file_read >> j;
    //    //    file_read.close();
    //    //    std::cout << "Existing JSON data read successfully." << std::endl;
    //    //}
    //    //else {
    //    //    // Если файл не существует или не может быть открыт, создаем новый объект JSON
    //    //    j = json::object();
    //    //    j["works"] = json::array();
    //    //    std::cout << "File not found or unable to open, creating new JSON object." << std::endl;
    //    //}
    //}
    //catch (const std::exception& e) {
    //    std::cerr << "Error reading JSON file: " << e.what() << std::endl;
    //    return;
    //}

    msclr::interop::marshal_context context;

    std::string last_place_of_work = context.marshal_as<std::string>(work->get_last_place_of_work());

    std::string position = context.marshal_as<std::string>(work->get_position());

    std::string work_experienc_date = context.marshal_as<std::string>(work->get_work_experienc_date());

    std::string Date_and_reasons_for_dismissal = context.marshal_as<std::string>(work->get_Date_and_reasons_for_dismissal());

    std::string news_about_the_withdrawal_of_pensions = context.marshal_as<std::string>(work->get_news_about_the_withdrawal_of_pensions());

    std::string information_about_past_work = context.marshal_as<std::string>(work->get_information_about_past_work());

    std::string place_of_actual_residence = context.marshal_as<std::string>(work->get_place_of_actual_residence());

    std::string place_of_residence_according_to_state_registration = context.marshal_as<std::string>(work->get_place_of_residence_according_to_state_registration());

    std::string Work_experience = context.marshal_as<std::string>(work->get_Work_experience());

    // Додавання нового користувача
    json new_user = {
        {"last_place_of_work", last_place_of_work},
        {"position", position},
        {"work_experienc_date", work_experienc_date},
        {"Date_and_reasons_for_dismissal", Date_and_reasons_for_dismissal},
        {"news_about_the_withdrawal_of_pensions", news_about_the_withdrawal_of_pensions},
        {"information_about_past_work", information_about_past_work},
        {"place_of_actual_residence", place_of_actual_residence},
        {"place_of_residence_according_to_state_registration", place_of_residence_according_to_state_registration},
        {"Work_experience", Work_experience}
    };

    //// Додавання нового користувача до масиву
    //j["employee_work"].push_back(new_user);
    //std::cout << "New user added to JSON data: " << new_user.dump(4) << std::endl;

    //// Запись измененных данных обратно в файл
    //try {
    //    std::ofstream file_write(filename);
    //    if (file_write.is_open()) {
    //        file_write << j.dump(4);  // Запись с отступами для лучшей читаемости
    //        file_write.close();
    //        std::cout << "Data successfully written to " << filename << std::endl;
    //        std::cout << "New JSON data: " << j.dump(4) << std::endl;
    //    }
    //    else {
    //        std::cerr << "Unable to open JSON file for writing" << std::endl;
    //    }
    //}
    //catch (const std::exception& e) {
    //    std::cerr << "Error writing to JSON file: " << e.what() << std::endl;
    //}
    return new_user;
}

json Serialization::save_vacation(List<_vacation^>^ vacations)
{
    // Додавання нового користувача
 
    json payed_vac;
    json unpayed_vac;
    json sick_vac;
    for (int i = 0; i < vacations->Count; i++)
    {
        json new_user;
        if (dynamic_cast<payed_vacation^> (vacations[i]))
        {
            new_user = {
                {"day_duration", vacations[i]->get_day_duration()},
                {"date", ToStr(vacations[i]->get_date())},
                {"period", ToStr(vacations[i]->get_period())},
                {"order", ToStr(vacations[i]->get_order())},
                {"payment", vacations[i]->get_payment()}
                };
            payed_vac.push_back(new_user);
           
        }
        else if (dynamic_cast<unpayed_vacation^> (vacations[i]))
        {
            new_user = {
                {"day_duration", vacations[i]->get_day_duration()},
                {"date", ToStr(vacations[i]->get_date())},
                {"period", ToStr(vacations[i]->get_period())},
                {"order", ToStr(vacations[i]->get_order())},
                

            };
            unpayed_vac.push_back(new_user);
        }
        else if (dynamic_cast<sick_leave^> (vacations[i]))
        {
            new_user = {
               {"day_duration", vacations[i]->get_day_duration()},
               {"date", ToStr(vacations[i]->get_date())},
               {"period", ToStr(vacations[i]->get_period())},
               {"order", ToStr(vacations[i]->get_order())},
               {"payment", vacations[i]->get_payment()},
               {"disease" , ToStr(vacations[i]->get_disease())}
            };
            sick_vac.push_back(new_user);
        }
    }

    json vac = {
        {"payed_vacations", payed_vac},
        {"unpayed_vacations", unpayed_vac},
        {"sick_leave", sick_vac}
    };
    return vac;
}



//json Serialization::save_employee_awards(_employee_awards^ awards)
//{
//    //std::string filename = "employee_awards.json";
//    //std::ifstream file_read(filename);
//    //json j;
//
//    //if (file_read.is_open()) {
//    //    // Завантаження існуючих даних
//    //    file_read >> j;
//    //    file_read.close();
//    //}
//
//    // Додавання нового користувача
//    json new_user;
//    auto awards_ = awards->get_awards();
//    for (int i = 0; i < awards_->Count; i++)
//    {
//        if (dynamic_cast<medal^> (awards_[i]))
//        {
//            new_user.push_back({
//                "name_award", ToStr(awards_[i]->get_name_awards())
//                });
//
//            new_user.push_back({
//                "gifter", ToStr(awards_[i]->get_gifter())
//                });
//
//            new_user.push_back({
//                "date", ToStr(awards_[i]->get_date())
//                });
//
//            new_user.push_back({
//                "signature", ToStr(awards_[i]->get_signature())
//                });
//            if (medal^ m = dynamic_cast<medal^> (awards_[i]))
//            {
//                new_user.push_back({
//               "marit", ToStr(m->get_merit())
//                    });
//            }
//        }
//        else if (dynamic_cast<gratitude^> (awards_[i]))
//        {
//            new_user.push_back({
//                "name_award", ToStr(awards_[i]->get_name_awards())
//                });
//
//            new_user.push_back({
//                "gifter", ToStr(awards_[i]->get_gifter())
//                });
//
//            new_user.push_back({
//                "date", ToStr(awards_[i]->get_date())
//                });
//
//            new_user.push_back({
//                "signature", ToStr(awards_[i]->get_signature())
//                });
//            if (gratitude^ l = dynamic_cast<gratitude^> (awards_[i]))
//                new_user.push_back({
//                    "course", ToStr(l->get_course())
//                    });
//        }
//    }
//
//    //// Додавання нового користувача до масиву
//    //j["employee_awards"].push_back(new_user);
//
//    //// Запис змінених даних назад у файл
//    //std::ofstream file_write(filename);
//    //if (file_write.is_open()) {
//    //    file_write << j.dump(4);  // Запис з відступами для кращої читабельності
//    //    file_write.close();
//    //}
//    return new_user;
//}

json Serialization::save_employee_certificates(List <_certificate^>^ certificates)
{
    
    json new_user;
   
    for (int i = 0; i < certificates->Count; i++)
    {
        new_user.push_back({ { "name", ToStr(certificates[i]->get_the_name_of_the_certificate())},
            {"location", ToStr(certificates[i]->get_location())},
            {"date", ToStr(certificates[i]->get_Date_of_receiving_the_certificate())},
            {  "points", ToStr(certificates[i]->get_points()) }
            });
        
           
        }
    
    return new_user;
}

json Serialization::save_family_status(Family_status^ family)
{
    json members;
    for (int i = 0; i < family->get_family_members()->Count; i++)
    {
        members.push_back({ { "PIB", ToStr(family->get_family_members()[i]->get_PIB())},
            {"Date_of_birth", ToStr(family->get_family_members()[i]->get_date_of_birthday())},
            {"level_relatives", ToStr(family->get_family_members()[i]->get_level_relatives())},
            });


    }

    json new_user = {
        {"family_status", ToStr(family->get_family_stats())},
        {"family_members", members},
    };
    return new_user;
}

json Serialization::save_salary(List<_salary^>^ sal)
{
    json new_user;
    json pension_;
    json fop_;
    json government_;
    json free_lancer_;
    for (int i = 0; i < sal->Count; i++)
    {
        if (dynamic_cast<pension^> (sal[i]))
        {
            new_user = {
                {"Salary", sal[i]->get_money()},
                {"Bonus",  sal[i]->get_bonus()},
                
            };
            pension_.push_back(new_user);
        }
        else if (dynamic_cast<FOP^> (sal[i]))
        {
            new_user = {
                {"Salary", sal[i]->get_money()},
                {"Bonus",  sal[i]->get_bonus()},

            };
            fop_.push_back(new_user);
        }
        else if (dynamic_cast<government^> (sal[i]))
        {
            new_user = {
                {"Salary", sal[i]->get_money()},
                {"Bonus",  sal[i]->get_bonus()},

            };
            government_.push_back(new_user);
        }
        else if (dynamic_cast<free_lancer^> (sal[i]))
        {
            new_user = {
               {"Salary", sal[i]->get_money()},
               {"Bonus",  sal[i]->get_bonus()},

            };
            free_lancer_.push_back(new_user);
        }
    }
    json object = {
        {"pension", pension_ },
        {"fop", fop_},
        {"government", government_ },
        {"free_lancer", free_lancer_}
    };
    return object;
}

Passport_data^ Serialization::read_passport_data(json Passport)
{
    std::string family = Passport["Family status"];
    std::string surname = Passport["Surname"];
    std::string name = Passport["Name"];
    std::string patronymic = Passport["Patronymic"];
    std::string sex = Passport["Sex"];
    std::string dob = Passport["Date of birthday"];
    std::string nationality = Passport["Nationality"];
    std::string ipn = Passport["IPN"];
    std::string adres = Passport["adres"];
    Passport_data^ passport = gcnew Passport_data(gcnew String(family.c_str()), gcnew String(surname.c_str()),
        gcnew String(name.c_str()), gcnew String(patronymic.c_str()), gcnew String(sex.c_str()), gcnew String(dob.c_str()),
        gcnew String(nationality.c_str()), gcnew String(ipn.c_str()), gcnew String(adres.c_str()));
       return passport;
}

_education^ Serialization::read_education(json education_)
{
    json new_ed = education_["inf"];
    List<_education_info^>^ info = gcnew List<_education_info^>();
    for (int i = 0;i<new_ed.size(); i++)
    {
        std::string name = new_ed[i]["name"];
        std::string education_level = new_ed[i]["education_level"];
        std::string diplom = new_ed[i]["diplom"];
        std::string graduation_year = new_ed[i]["graduation_year"];
        std::string science = new_ed[i]["science"];
        
        info->Add(gcnew _education_info(gcnew String(name.c_str()), gcnew String(education_level.c_str()),
            gcnew String(diplom.c_str()), gcnew String(graduation_year.c_str()), gcnew String(science.c_str())));
    }

    _education^ educat = gcnew _education(info);
    return educat;
}

military_registration^ Serialization::read_military_registration(json military)
{
    std::string rank = military["rank"];
    std::string position = military["position"];
    int military_experience = military["military_experience"];
    std::string suitability = military["suitability"];
    bool suit = suitability == "+";
    military_registration^ military__ = gcnew military_registration(gcnew String(rank.c_str()), gcnew String(position.c_str()),
        military_experience, suit);
    return military__;
}
List<_diseases^>^ Serialization::read_diseases(json diseases)
{

    List<_diseases^>^ dis = gcnew List<_diseases^>();
    for (int i = 0; i < diseases.size(); i++) {
        json d = diseases[i];
        std::string disability_group = d["disability_group"];
        std::string name = d["name"];
        std::string type = d["type"];
        dis->Add(gcnew _diseases(gcnew String(disability_group.c_str()), gcnew String(name.c_str()), gcnew String( type.c_str())));
    }
    return dis;
    
}
_work^ Serialization::read_work(json work)
{
    std::string last_place_of_work = work["last_place_of_work"];
    std::string position = work["position"];
    std::string work_experienc_date = work["work_experienc_date"];
    std::string Date_and_reasons_for_dismissal = work["Date_and_reasons_for_dismissal"];
    std::string news_about_the_withdrawal_of_pensions = work["news_about_the_withdrawal_of_pensions"];
    std::string information_about_past_work = work["information_about_past_work"];
    std::string place_of_actual_residence = work["place_of_actual_residence"];
    std::string place_of_residence_according_to_state_registration = work["place_of_residence_according_to_state_registration"];
    std::string Work_experience = work["Work_experience"];
    _work^ worka = gcnew _work(gcnew String(last_place_of_work.c_str()), 
        gcnew String(position.c_str()), 
        gcnew String(work_experienc_date.c_str()), 
        gcnew String(Date_and_reasons_for_dismissal.c_str()), 
        gcnew String(news_about_the_withdrawal_of_pensions.c_str()), 
        gcnew String(information_about_past_work.c_str()),
        gcnew String(place_of_actual_residence.c_str()), 
        gcnew String(place_of_residence_according_to_state_registration.c_str()), 
        gcnew String(Work_experience.c_str()));
        
    return worka;
}
List<_vacation^>^ Serialization::read_vacation(json vacation)
{
    List<_vacation^>^ vac = gcnew List<_vacation^>();
    if (!vacation.is_null() ) {
        for (int i = 0; i < vacation["payed_vacations"].size(); i++)
        {
            json v = vacation["payed_vacations"][i];
            int day_duration = v["day_duration"];
            std::string date = v["date"];
            std::string period = v["period"];
            std::string order = v["order"];
            //std::string type = v["payed_vacations"]["type"];

            float payment = v["payment"];
            vac->Add(gcnew payed_vacation(payment, day_duration, gcnew String(date.c_str()), gcnew String(period.c_str()), gcnew String(order.c_str())));
        }
        for (int i = 0; i < vacation["sick_leave"].size(); i++)
        {
            json v = vacation["sick_leave"][i];
            int day_duration = v["day_duration"];
            std::string date = v["date"];
            std::string period = v["period"];
            std::string order = v["order"];
           // std::string type = v["sick_leave"]["type"];

            
           
                float payment = v["payment"];
                std::string disease = v["disease"];
                vac->Add(gcnew sick_leave(gcnew String(disease.c_str()), payment, day_duration, gcnew String(date.c_str()), gcnew String(period.c_str()), gcnew String(order.c_str())));
            
        }
        for (int i = 0; i < vacation["unpayed_vacations"].size(); i++)
        {
            json v = vacation["unpayed_vacations"][i];
            int day_duration = v["day_duration"];
            std::string date = v["date"];
            std::string period = v["period"];
            std::string order = v["order"];
           // std::string type = v["unpayed_vacations"]["type"];
            vac->Add(gcnew unpayed_vacation(day_duration, gcnew String(date.c_str()), gcnew String(period.c_str()), gcnew String(order.c_str())));


        }
   
    }
    return vac;
}
List<_certificate^>^ Serialization::read_employee_certificates(json certificates)
{
    List<_certificate^>^ cer = gcnew List<_certificate^>();
    for (int i = 0; i < certificates.size(); i++)
    {
        json c = certificates[i];
        std::string name = c["name"];
        std::string Date_of_receiving = c["date"];
        std::string points = c["points"];
        std::string location = c["location"];
        cer->Add(gcnew _certificate(gcnew String(name.c_str()), gcnew String(Date_of_receiving.c_str()), gcnew String(points.c_str()), gcnew String(location.c_str())));
    }
    return cer;
}
Family_status^ Serialization::read_family_status(json family)
{
    List <family_member^>^ fam = gcnew List <family_member^>();
    std::string family_stats = family["family_status"];
    for (int i = 0; i < family["family_members"].size(); i++)
    {
        json fa = family["family_members"][i];
        std::string PIB = fa["PIB"];
        std::string date_of_birthday = fa["Date_of_birth"];
        std::string level_relatives = fa["level_relatives"];
        fam->Add(gcnew family_member(gcnew String(PIB.c_str()), gcnew String(date_of_birthday.c_str()), gcnew String(level_relatives.c_str())));
    }
    Family_status^ status = gcnew Family_status(gcnew String(family_stats.c_str()), fam);
    return status;
}
List<_salary^>^ Serialization::read_salary(json sal)
{
    List<_salary^>^ salar = gcnew List<_salary^>();
    for (int i = 0; i < sal["pension"].size(); i++)
    {
        json slr = sal["pension"][i];
        float money = slr["Salary"];
        float bonus = slr["Bonus"];

        salar->Add(gcnew pension(  money,  bonus));
    }
    for (int i = 0; i < sal["fop"].size(); i++)
    {
        json slr = sal["fop"][i];
        float money = slr["Salary"];
        float bonus = slr["Bonus"];

        salar->Add(gcnew FOP(money, bonus));
    }

    for (int i = 0; i < sal["government"].size(); i++)
    {
        json slr = sal["government"][i];
        float money = slr["Salary"];
        float bonus = slr["Bonus"];

        salar->Add(gcnew government(money, bonus));
    }

    for (int i = 0; i < sal["free_lancer"].size(); i++)
    {
        json slr = sal["free_lancer"][i];
        float money = slr["Salary"];
        float bonus = slr["Bonus"];

        salar->Add(gcnew free_lancer(money, bonus));
    }
    return salar;
}
Health^ Serialization::read_health(json health)
{
    std::string state_of_health = health["state_of_health"];
    json diseases = health["diseases"];

    std::string blood_type = health["blood_type"];
    Health^ heal = gcnew Health(gcnew String(state_of_health.c_str()), gcnew String(blood_type.c_str()), read_diseases(diseases));
    return heal;
}

List<_employee^>^ Serialization::getEmployees()
{
    
    std::string filename = "employees_info.json";
    json j;

    
   try {
        std::ifstream file_read(filename);
        if (file_read.is_open()) {
            file_read >> j;
            file_read.close();
        }
        else {
            // Если файл не существует или не может быть открыт, создаем новый объект JSON
            j = json::object();
            j["employees"] = json::array();
        }
        
     

        List<_employee^>^ list = gcnew List<_employee^>();
        
        for (int i = 0; i < j["employees"].size(); i++) {
            list->Add(gcnew _employee(read_passport_data(j["employees"][i]["passport"]), read_vacation(j["employees"][i]["vacation"]), 
                read_family_status(j["employees"][i]["family_status"]),
                read_work(j["employees"][i]["work"]), read_education(j["employees"][i]["education"]), read_military_registration(j["employees"][i]["military_registration"]),
                read_health(j["employees"][i]["health"]), read_salary(j["employees"][i]["salary"]),
                read_employee_certificates(j["employees"][i]["certeficates"])));
        }
        return list;
        
    }
    catch (const std::exception& e) {
        std::cerr << "Error reading JSON file: " << e.what() << std::endl;
        return gcnew List<_employee^>();
    }

    // TODO: parse data from json to List<_employee^>^ and return 
}


void Serialization::saveDataUser(_Admin^ admin) {
    std::string filename = "admin_info.json";
    json j;

    // Чтение существующих данных из файла
    try {
        std::ifstream file_read(filename);
        if (file_read.is_open()) {
            file_read >> j;
            file_read.close();
        }
        else {
            // Если файл не существует или не может быть открыт, создаем новый объект JSON
            j = json::object();
            j["users"] = json::array();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error reading JSON file: " << e.what() << std::endl;
        return;
    }

    msclr::interop::marshal_context context;

    std::string username = context.marshal_as<std::string>(admin->get_user_name());
    std::string name = context.marshal_as<std::string>(admin->get_name());
    std::string surname = context.marshal_as<std::string>(admin->get_surname());
    std::string email = context.marshal_as<std::string>(admin->get_email());
    std::string password = context.marshal_as<std::string>(admin->get_password());
    std::string phone_number = context.marshal_as<std::string>(admin->get_phone_number());

    // Додавання нового користувача
    json new_user = {
        {"Username", username},
        {"Name", name},
        {"Surname", surname},
        {"Email", email},
        {"Password", password},
        {"Phone Number", phone_number}
    };

    // Додавання нового користувача до масиву
    j["users"].push_back(new_user);

    // Запись измененных данных обратно в файл
    try {
        std::ofstream file_write(filename);
        if (file_write.is_open()) {
            file_write << j.dump(4);  // Запись с отступами для лучшей читаемости
            file_write.close();
            std::cout << "Data successfully written to " << filename << std::endl;
        }
        else {
            std::cerr << "Unable to open JSON file for writing" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error writing to JSON file: " << e.what() << std::endl;
    }
}


void Serialization::saveDataemployee(_employee^ finish) {
    std::string filename = "employees_info.json";
    json j;

    // Чтение существующих данных из файла
    try {
        std::ifstream file_read(filename);
        if (file_read.is_open()) {
            file_read >> j;
            file_read.close();
        }
        else {
            // Если файл не существует или не может быть открыт, создаем новый объект JSON
            j = json::object();
            j["employees"] = json::array();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error reading JSON file: " << e.what() << std::endl;
        return;
    }

    msclr::interop::marshal_context context;

    /*json military_data = save_military_registration(finish->get_military());
    std::cout << "Military data: " << military_data.dump(4) << std::endl;
    */
    json new_user = {
         {"passport", save_passport_data(finish->get_passport_inf())},
         {"education",save_education(finish->get_education())},
         {"military_registration",save_military_registration(finish->get_military())},
         {"health",save_health(finish->get_health())},
         {"work",save_work(finish->get_work()) },
         {"certeficates", save_employee_certificates(finish->get_certificates())},
         {"family_status", save_family_status(finish->get_family())},
        {"vacation", save_vacation(finish->get_vacations())},
        {"salary", save_salary(finish->get_salary())}
    };

    // Додавання нового користувача до масиву
    j["employees"].push_back(new_user);

    // Запись измененных данных обратно в файл
    try {
        std::ofstream file_write(filename);
        if (file_write.is_open()) {
            file_write << j.dump(4);  // Запись с отступами для лучшей читаемости
            file_write.close();
            std::cout << "Data successfully written to " << filename << std::endl;
        }
        else {
            std::cerr << "Unable to open JSON file for writing" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error writing to JSON file: " << e.what() << std::endl;
    }

    

    //save_passport_data(finish->get_passport_inf());
    //save_education(finish->get_education());
    //save_military_registration(finish->get_military());
    //save_health(finish->get_health());
    //save_work(finish->get_work());
    ////save_vacation(finish.);
    //save_employee_transfer(finish->get_transfer());
    //save_employee_awards(finish->get_employee_awards());
}

bool Serialization::checkPhoneNumber(std::string search_phone_number) {
    std::string filename = "packages_data.json";
    std::ifstream file_read(filename);
    json j;

    if (file_read.is_open()) {
        file_read >> j;
        file_read.close();

        for ( auto user : j["packages"]) {
            std::string recipient_phone_number = user["Phone_Recipient"];
            std::string sender_phone_number = user["Phone_Sender"];
            if (recipient_phone_number == search_phone_number || sender_phone_number == search_phone_number) {
                return true;
            }
        }
        return false;
    }
    return false;
}

//bool Serialization::deletePackage(long long unsigned int TTN_) {
//    std::string filename = "packages_data.json";
//    std::ifstream file_read(filename);
//    json j;
//
//    if (file_read.is_open()) {
//        file_read >> j;
//        file_read.close();
//        for (auto it = j["packages"].begin(); it != j["packages"].end(); ++it) {
//            long long unsigned int TTN = (*it)["TTN"];
//            if (TTN == TTN_) {
//                it = j["packages"].erase(it);
//                std::ofstream file_write(filename);
//                if (file_write.is_open()) {
//                    file_write << j.dump(4);
//                    file_write.close();
//                }
//                return true;
//            }
//        }
//        return false;
//    }
//    return false;
//}
bool Serialization::deletePackage(long long unsigned int TTN_) {
    std::string filename = "packages_data.json";
    std::ifstream file_read(filename);
    json j;

    if (file_read.is_open()) {
        file_read >> j;
        file_read.close();

        // Цикл для пошуку та видалення елементу з JSON-масиву
        for (auto it = j["packages"].begin(); it != j["packages"].end(); ) {
            if ((*it)["TTN"] == TTN_) {
                it = j["packages"].erase(it);  // Видалення і отримання наступного валідного ітератора
            }
            else {
                ++it;  // Збільшення ітератора, якщо поточний елемент не був видалений
            }
        }
        // Перезапис файлу з оновленим JSON
        std::ofstream file_write(filename);
        if (file_write.is_open()) {
            file_write << j.dump(4);
            file_write.close();
            return true;  // Видалення успішне
        }
    }
    return false;  // Файл не відкрився або запис не відбувся
}
void Serialization::saveDocumentationPackage(long long unsigned int TTN_, int price_) {
    std::string filename = "documentation.json";
    std::ifstream file_read(filename);
    json j;

    if (file_read.is_open()) {
        // Завантаження існуючих даних
        file_read >> j;
        file_read.close();
    }

    json new_data = {
        {"TTN", TTN_},
        {"price", price_}
    };

    j["data"].push_back(new_data);

    std::ofstream file_write(filename);
    if (file_write.is_open()) {
        file_write << j.dump(4);
        file_write.close();
    }
}

bool Serialization::deleteDocumentationPackage(long long unsigned int TTN_) {
    std::string filename = "documentation.json";
    std::ifstream file_read(filename);
    json j;

    if (file_read.is_open()) {
        file_read >> j;
        file_read.close();

        for (auto it = j["data"].begin(); it != j["data"].end(); ++it) {
            long long unsigned int TTN = (*it)["TTN"];
            if (TTN == TTN_) {
                // Видаляємо цей об'єкт
                it = j["packages"].erase(it);

                std::ofstream file_write(filename);
                if (file_write.is_open()) {
                    file_write << j.dump(4);
                    file_write.close();
                }
                return true;
            }
        }
        return false;
    }
    return false;
}

std::vector<std::unordered_map<std::string, std::string>> Serialization::getPackageData(std::string search_phone_number) {
    std::vector<std::unordered_map<std::string, std::string>> package_info;

    std::string filename = "packages_data.json";
    std::ifstream file_read(filename);
    json j;

    if (file_read.is_open()) {
        file_read >> j;
        file_read.close();

        for ( auto box : j["packages"]) {
            if (box["Phone_Sender"] == search_phone_number || box["Phone_Recipient"] == search_phone_number) {
                std::unordered_map<std::string, std::string> package_data = {
                    {"TTN", std::to_string(box["TTN"].get<long long unsigned int>())},
                    {"Sender", box["Sender"]},
                    {"Phone_Sender", box["Phone_Sender"]},
                    {"Dispatch", box["Dispatch"]},
                    {"Recipient", box["Recipient"]},
                    {"Phone_Recipient", box["Phone_Recipient"]},
                    {"Price",std::to_string(box["Price"].get<int>())},
                    {"Distance",std::to_string(box["Distance"].get<double>())},
                    {"Destination", box["Destination"]}
                };
                package_info.push_back(package_data);
            }
        }
    }

    return package_info;
}

std::unordered_map<std::string, std::string> Serialization::getUserData(std::string search_email) {
    std::unordered_map<std::string, std::string> user_info;

    std::string filename = "users_data.json";
    std::ifstream file_read(filename);
    json j;
    if (file_read.is_open()) {
        file_read >> j;
        file_read.close();

        for ( auto user : j["users"]) {
            if (user["email"] == search_email) {
                user_info = {
                    {"first_name", user["first_name"]},
                    {"sur_name", user["sur_name"]},
                    {"last_name", user["last_name"]},
                    {"phone_number", user["phone_number"]},
                };
                break;
            }
        }
    }
    return user_info;
}

bool Serialization::checkEmail(std::string search_email) {
    std::string filename = "users_data.json";
    std::ifstream file_read(filename);
    json j;

    file_read >> j;
    file_read.close();

    for ( auto user : j["users"]) {
        std::string user_email = user["email"];
        if (user_email == search_email) {
            return true;
        }
    }

    return false;
}

//tut
bool Serialization::findUser(System::String^ username, System::String^ password) {
    std::string filename = "admin_info.json";
    json j;

    // Чтение существующих данных из файла
    try {
        std::ifstream file_read(filename);
        if (file_read.is_open()) {
            file_read >> j;
            file_read.close();
        }
        else {
            std::cerr << "Could not open the file!" << std::endl;
            return false;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error reading JSON file: " << e.what() << std::endl;
        return false;
    }

    msclr::interop::marshal_context context;
    std::string username_std = context.marshal_as<std::string>(username);
    std::string password_std = context.marshal_as<std::string>(password);

    
    // Проверка учетных данных пользователя
    for (const auto& user : j["users"]) {
        if (user["Username"] == username_std && user["Password"] == password_std) {
            return true;
        }
    }

    return false;
}

void Serialization::changeEmail(std::string email_, std::string new_email, std::string check_password) {
    std::string filename = "users_data.json";
    std::ifstream file_read(filename);
    json j;

    if (file_read.is_open()) {
        file_read >> j;
        file_read.close();

        for (auto user : j["users"]) {
            std::string user_email = user["email"];
            std::string user_password = user["password"];
            if (user_email == email_ || user_password == check_password) {
                if (new_email != email_ || !checkEmail(new_email)) {
                    user["email"] = new_email;
                    std::ofstream file_write(filename);
                    if (file_write.is_open()) {
                        file_write << j.dump(4);
                        file_write.close();
                    }
                    break;
                }
            }
        }
    }
}

void Serialization::changePassword(std::string email_, std::string password_, std::string new_password) {
    std::string filename = "users_data.json";
    std::ifstream file_read(filename);
    json j;

    if (file_read.is_open()) {
        file_read >> j;
        file_read.close();

        for (auto user : j["users"]) {
            if (user["email"] == email_ || user["password"] == password_) {
                if (new_password != password_) {
                    user["password"] = new_password;
                    std::ofstream file_write(filename);
                    if (file_write.is_open()) {
                        file_write << j.dump(4);
                        file_write.close();
                    }
                    break;
                }
            }
        }
    }
}

std::string Serialization::getFullName(std::string email_) {
    std::string full_name;

    std::string filename = "users_data.json";
    std::ifstream file_read(filename);
    json j;

    if (file_read.is_open()) {
        file_read >> j;
        file_read.close();

		for ( auto user : j["users"]) {
			if (user["email"] == email_) {
				std::string surname = user["first_name"];
				std::string name = user["sur_name"];
				std::string last_name = user["last_name"];
				full_name = surname + " " + name + " " + last_name;
				break;
			}
		}
	}
	return full_name;
}

Serialization::Serialization()
{
    _data = 0;
}

Serialization::Serialization(Serialization^ other)
{
    this->_data = other->_data;
}




