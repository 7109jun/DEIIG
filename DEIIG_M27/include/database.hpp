#pragma once

#include <filesystem>
#include <string>
#include <vector>

namespace deiig::database {

struct Column {
    std::string name;
};

struct Table {
    std::string name;
    std::vector<Column> columns;
    std::vector<std::vector<std::string>> rows;
};

struct Database {
    std::vector<Table> tables;
};

bool load(const std::filesystem::path& path, Database& db, std::string& error);
bool save(const std::filesystem::path& path, const Database& db, std::string& error);

Table* find_table(Database& db, const std::string& name);
const Table* find_table(const Database& db, const std::string& name);

bool create_table(Database& db, const std::string& name, const std::vector<std::string>& columns, std::string& error);
bool drop_table(Database& db, const std::string& name, std::string& error);
bool insert_row(Database& db, const std::string& table, const std::vector<std::string>& values, std::string& error);
bool update_cell(Database& db, const std::string& table, std::size_t row, const std::string& column, const std::string& value, std::string& error);
bool delete_row(Database& db, const std::string& table, std::size_t row, std::string& error);

std::vector<std::vector<std::string>> select_rows(const Database& db, const std::string& table, const std::string& where_column = {}, const std::string& where_value = {});
std::string format_table(const Table& table);

} // namespace deiig::database
