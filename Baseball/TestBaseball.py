import unittest

# import the module(s) to be tested:
from Baseball import *

class TestBaseball(unittest.TestCase):

    @classmethod
    def setUpClass(self):
        """ Open the database connection """
        self.connection = connect()

    @classmethod
    def tearDownClass(self):
        """ Close the database connection when all tests are finished """
        self.connection.close()

    def setUp(self):
        """
        Creates a cursor that can be used in tests. setUp() is called before
        every test case.
        """
        self.cursor = self.connection.cursor()

    def tearDown(self):
        """
        Ensure that changes to the database are not saved, and don't interfere
        with other tests. tearDown() is called after every test case.
        """
        self.cursor.close()
        self.connection.rollback()


    def test_addPlayer_teamExists(self):
        """
        Tests that a new baseball player can be added to an existing team
        """

        newPlayerId = add_player(self.connection, "Chris Bentivenga", 2, "OF")

        self.assertIsNotNone(newPlayerId)
        
        query = "SELECT * FROM Players WHERE id = ?"
        self.cursor.execute(query, [str(newPlayerId)])

        result = self.cursor.fetchone()
        self.assertEqual("Chris Bentivenga", result[1])
        self.assertEqual(2, result[2])
        self.assertEqual("OF", result[3])
	

if __name__ == '__main__':
    unittest.main()
