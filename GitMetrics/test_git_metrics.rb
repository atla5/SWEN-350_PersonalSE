require_relative 'git_metrics'
require 'test/unit'

class TestGitMetrics < Test::Unit::TestCase

  def test_commit_example
  	assert_equal 2, num_commits(["commit abc", "commit 123"]), "Should have counted two commits"
  end

  def test_commit_middle
    assert_equal 1, num_commits(["commit abc", "this commit"])
  end

  def test_commit_beginRedHerring
    assert_equal 1, num_commits(["commit abc","committing this..."])
  end

  #test num_developers
  def test_num_devs_norm
    lsAuthorLine = ["Author: J F <em1>","Author: E K <em2>"]
    assert_equal 2, num_developers(lsAuthorLine); 
  end

  def test_num_devs_duplicate
    lsAuthorLine = ["Author: J F <e1>","Author: E K <e2>","Author: J F <e1>"]
    assert_equal 2, num_developers(lsAuthorLine); 
  end

  def test_dates_with_three_days
  	exp = [ "Date:  Sun Jan 26 21:25:22 2014 -0600", \
  			"Date:  Sun Jan 23 21:25:22 2014 -0600", \
  			"Date:  Sun Jan 25 21:25:22 2014 -0600"]
    assert_equal 3, days_of_development(exp), "Should have been a 3 days difference"
  end

  #Add more tests here
  def test_dates_one_day
    exp = ["Date:  Sun Jan 25 21:25:22 2014 -0600"]
    assert_equal 1, days_of_development(exp)
  end

  def test_dates_empty
    exp = []
    assert_equal 0, days_of_development(exp)
  end


end
