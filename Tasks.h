#include <string>
#include <ctime>

#pragma once

class Tasks {
private:
  int id;
  std::string description;
  time_t created;
  time_t deadline;
  bool isDone;

public:
  Tasks();
  Tasks(int id, const std::string& description,
        const time_t& created,
        const time_t& deadline);

  int getId() const;
  const std::string& getDescription() const;
  const time_t& getCreated() const ;
  const time_t& getDeadline() const;
  bool getIsDone() const ;
  void setIsDone(bool isDone);
  void setCreated(const time_t& created);
  void setDeadline(const time_t& deadline);
  void setId(const int id) { this->id = id;}
  void setDescription(const std::string& description) { this->description = description;}

};
