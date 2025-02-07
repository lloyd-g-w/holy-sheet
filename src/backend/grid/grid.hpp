#pragma once

#include <unordered_map>

#include "../cell/cell.hpp"
#include "../common.hpp"

namespace std_cells {

class grid {
  private:
    typedef std::unordered_map<pos, cell, pos_hash> cell_map;

  public:
    grid(int rows = 1000, int cols = 1000)
        : m_rows(rows), m_cols(cols), m_cells() {}

    // Main methods
    // Creation, deletion, and evaluation
    void create_cell(pos pos);
    void delete_cell(pos pos);
    void evaluate_cell(pos pos);

    // Getters
    const cell::data &get_cell_data(pos pos);
    const int get_rows();
    const int get_cols();

    // Public helper methods
    static pos str_to_pos(str pos_str);
    static str pos_to_str(pos pos);
    static str num_to_alpha(int num);

  private:
    // Members
    int m_rows;
    int m_cols;
    cell_map m_cells;

    // Private helper methods
    bool is_set(pos pos);
    bool valid_pos(pos pos);
    cell &get_cell_mut(pos pos);
};

}  // namespace std_cells
