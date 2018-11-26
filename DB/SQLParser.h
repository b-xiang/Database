#ifndef SQLPARSER_SQLPARSER_H
#define SQLPARSER_SQLPARSER_H

#include "SQLParserResult.h"
#include "sql/statements.h"

namespace hsql {

  class SQLParser {
   public:
	// 输入sql语句，如果转换成功返回true，失败返回false，但不代表sql语句有效，检查有效可用result->isValid();
    static bool parse(const std::string& sql, SQLParserResult* result);
    // 解析为符号
    static bool tokenize(const std::string& sql, std::vector<int16_t>* tokens);

   private:
    SQLParser();
  };

} // namespace hsql


#endif