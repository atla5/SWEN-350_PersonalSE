class AddThumbersToThought < ActiveRecord::Migration
  def self.up
    add_column :thoughts, :thumbers, :integer
  end

  def self.down
    remove_column :thoughts, :thumbers
  end
end
