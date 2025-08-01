//  SuperTux
//  Copyright (C) 2020 A. Semphris <semphris@protonmail.com>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "supertux/menu/editor_save_as.hpp"

#include "editor/editor.hpp"
#include "gui/dialog.hpp"
#include "gui/menu_item.hpp"
#include "gui/menu_manager.hpp"
#include "supertux/level.hpp"
#include "supertux/gameconfig.hpp"
#include "supertux/menu/menu_storage.hpp"
#include "util/gettext.hpp"
#include "video/compositor.hpp"

EditorSaveAs::EditorSaveAs(bool do_switch_file) :
  m_filename(Editor::current()->get_levelfile()),
  m_do_switch_file(do_switch_file)
{
  add_label(do_switch_file ? _("Save Level as") : _("Save Copy"));

  add_hl();

  add_textfield(_("File name"), &m_filename);
  add_entry(MNID_SAVE, _("Save"));

  add_hl();

  add_entry(MNID_CANCEL, _("Cancel"));
}

EditorSaveAs::~EditorSaveAs()
{
  auto editor = Editor::current();
  if (editor == nullptr) {
    return;
  }
  editor->m_reactivate_request = true;
}

void
EditorSaveAs::menu_action(MenuItem& item)
{
  auto editor = Editor::current();

  switch (item.get_id())
  {
    case MNID_SAVE:
      editor->m_save_request = true;
      editor->m_save_request_filename = m_filename;
      editor->m_save_request_switch = m_do_switch_file;
      MenuManager::instance().clear_menu_stack();
      break;

    case MNID_CANCEL:
      MenuManager::instance().clear_menu_stack();
      break;

    default:
      break;
  }
}
